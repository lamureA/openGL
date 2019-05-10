//
// Created by alexandre on 09/05/19.
//

#ifndef TP1_PROGRAM_H
#define TP1_PROGRAM_H

#include <string>

class Program {
private:
    char *log;
    bool ready;

    GLuint compile_shader(std::string& shader_src, GLenum shader_type);
    bool check_compile(GLuint shader);

    GLuint link(GLuint vertex_shader, GLuint fragment_shader);
    bool check_link(GLuint program_id);

public:
    Program();
    ~Program();

    static Program *make_program(std::string& vertex_shader_src, std::string& fragment_shader_src);
    char *get_log();
    bool is_ready();
    void use();
};


#endif //TP1_PROGRAM_H
