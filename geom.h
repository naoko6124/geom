#include <fstream>
#include <vector>

struct geom
{
    struct vertex
    {
        float position[3] = {0.0f, 0.0f, 0.0f};
        float normal[3] = {0.0f, 0.0f, 0.0f};
        float uv[2] = {0.0f, 0.0f};
    };

    char name[4] = { 0x47, 0x45, 0x4F, 0x4D };
    char version[4] = { 0x00, 0x00, 0x00, 0x01 };

    std::vector<vertex> vertices;
    std::vector<int> indices;

    bool read(const char* path)
    {
        std::ifstream file(path);

        // verify if the file is geom
        file.seekg(0);
        char fname[4];
        file.read(fname, 4);
        if (memcmp(fname, name, 4))
        {
            printf("file is not geom");
            return false;
        }

        // verify if the version is 0.0.0.1
        file.seekg(4);
        char fversion[4];
        file.read(fversion, 4);
        if (memcmp(&fversion, &version, 4))
        {
            printf("file version is not 0.0.0.1");
            return false;
        }

        // get vertex buffer offset
        file.seekg(24);
        int vertex_offset;
        file.read((char*)&vertex_offset, 4);

        // get vertex buffer lenght
        file.seekg(28);
        int vertex_length;
        file.read((char*)&vertex_length, 4);
        
        // get index buffer offset
        file.seekg(40);
        int index_offset;
        file.read((char*)&index_offset, 4);

        // get index buffer lenght
        file.seekg(44);
        int index_length;
        file.read((char*)&index_length, 4);

        // get vertex buffer
        for (int i = vertex_offset; i < vertex_offset + vertex_length; i += 32)
        {
            vertex v;

            file.seekg(i);
            file.read((char*)&v.position, 12);

            file.seekg(i+12);
            file.read((char*)&v.normal, 12);

            file.seekg(i+24);
            file.read((char*)&v.uv, 8);

            vertices.push_back(v);
        }

        // get index buffer
        for (int i = index_offset; i < index_offset + index_length; i += 4)
        {
            int index;

            file.seekg(i);
            file.read((char*)&index, 4);

            indices.push_back(index);
        }

        file.close();
        return true;
    }

    bool write(const char* path)
    {
        // calculate the offsets and lengths of headers
        int data_offset = 16 + 16 + 16;
        int vertex_offset = data_offset;
        int vertex_length = vertices.size() * sizeof(vertex);
        int index_offset = data_offset + vertex_length;
        int index_length = indices.size() * sizeof(int);
        int data_length = vertex_length + index_length;

        std::ofstream file(path);
        file.clear();

        // write the file header
        file.write((const char*)&name, 4);
        file.write((const char*)&version, 4);
        file.write((const char*)&data_offset, 4);
        file.write((const char*)&data_length, 4);

        // write the vertex info header
        file.write("VERTEX  ", 8);
        file.write((const char*)&vertex_offset, 4);
        file.write((const char*)&vertex_length, 4);

        // write the index info header
        file.write("INDEX   ", 8);
        file.write((const char*)&index_offset, 4);
        file.write((const char*)&index_length, 4);

        // write the vertex buffer
        for (vertex& v : vertices)
        {
            file.write((const char*)&v.position, 12);
            file.write((const char*)&v.normal, 12);
            file.write((const char*)&v.uv, 8);
        }

        // write the index buffer
        for (int& i : indices)
        {
            file.write((const char*)&i, 4);
        }

        file.close();
        return true;
    }
};