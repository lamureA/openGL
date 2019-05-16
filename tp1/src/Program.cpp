//
// Created by alexandre on 09/05/19.
//

#include <GL/glew.h>
#include <GL/gl.h>
#include <vector>
#include "Program.h"


Program::Program(): log(nullptr), ready(false)
{}

GLuint Program::compile_shader(std::string& shader_src, GLenum shader_type) {
    GLuint shader = glCreateShader(shader_type);
    const GLchar *source = (const GLchar *)shader_src.c_str();
    glShaderSource(shader, 1, &source, nullptr);
    glCompileShader(shader);
    return shader;
}

bool Program::check_compile(GLuint shader) {
    GLint isCompiled = 0;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);
    if(isCompiled == GL_FALSE)
    {
        GLint maxLength = 0;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);

        // The maxLength includes the NULL character
        std::vector<GLchar> infoLog(maxLength);
        glGetShaderInfoLog(shader, maxLength, &maxLength, &infoLog[0]);

        // We don't need the shader anymore.
        glDeleteShader(shader);

        // Fill the attributes
        this->log = &infoLog[0];
        this->ready = false;

        // We leave
        return false;
    }
    return true;
}

void Program::link(GLuint vertex_shader, GLuint fragment_shader) {
    // Create program object.
    GLuint program_id = glCreateProgram();

    // Attach our shaders to our program
    glAttachShader(program_id, vertex_shader);
    glAttachShader(program_id, fragment_shader);

    // Link our program
    glLinkProgram(program_id);

    this->program_id = program_id;
}

bool Program::check_link() {
    GLint isLinked = 0;
    glGetProgramiv(this->program_id, GL_LINK_STATUS, (int *)&isLinked);
    if (isLinked == GL_FALSE)
    {
        GLint maxLength = 0;
        glGetProgramiv(this->program_id, GL_INFO_LOG_LENGTH, &maxLength);

        // The maxLength includes the NULL character
        std::vector<GLchar> infoLog(maxLength);
        glGetProgramInfoLog(this->program_id, maxLength, &maxLength, &infoLog[0]);

        // We don't need the program_id anymore.
        glDeleteProgram(this->program_id);

        // Fill the attributes
        this->log = &infoLog[0];
        this->ready = false;

        // We leave
        return false;
    }
}


Program *Program::make_program(std::string &vertex_shader_src, std::string &fragment_shader_src) {
    Program *program = new Program();

    // Compile shaders
    GLuint vertex_shader = program->compile_shader(vertex_shader_src, GL_VERTEX_SHADER);
    if (!program->check_compile(vertex_shader))
        return program;

    GLuint fragment_shader = program->compile_shader(fragment_shader_src, GL_FRAGMENT_SHADER);
    if (!program->check_compile(fragment_shader))
        return program;


    program->link(vertex_shader, fragment_shader);
    if (program->check_link())
        program->ready = true;


    // Always detach shaders after a successful link.
    glDetachShader(program->program_id, vertex_shader);
    glDetachShader(program->program_id, fragment_shader);


    return program;
}

char *Program::get_log() {
    return log;
}

bool Program::is_ready() {
    return ready;
}

void Program::use() {
    if (this->is_ready())
        glUseProgram(this->program_id);
}
