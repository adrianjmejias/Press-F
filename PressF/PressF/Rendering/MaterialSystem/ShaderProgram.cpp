#include "PressF/pch.h"
#include "ShaderProgram.h"

namespace PF
{
    Owns<ShaderProgram> ShaderProgram::FromFiles(const std::string& vertexPath, const std::string& fragmentPath, const std::string& geometryPath)
    {
        Owns<ShaderProgram> s{ new ShaderProgram() };
        s->vPath = vertexPath;
        s->fPath = fragmentPath;
        s->ReCompile();

        return s;
    }
    void ShaderProgram::ReCompile()
     {
         const char* geometryPath = nullptr;

         std::string vertexCode;
         std::string fragmentCode;
         std::string geometryCode;
         std::ifstream vShaderFile;
         std::ifstream fShaderFile;
         std::ifstream gShaderFile;
         // ensure ifstream objects can throw exceptions:
         vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
         fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
         gShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
         try
         {
             // open files
             vShaderFile.open(vPath.c_str());
             fShaderFile.open(fPath.c_str());
             std::stringstream vShaderStream, fShaderStream;
             // read file's buffer contents into streams
             vShaderStream << vShaderFile.rdbuf();
             fShaderStream << fShaderFile.rdbuf();
             // close file handlers
             vShaderFile.close();
             fShaderFile.close();
             // convert stream into string
             vertexCode = vShaderStream.str();
             fragmentCode = fShaderStream.str();
             // if geometry shader path is present, also load a geometry shader
             if (geometryPath != nullptr)
             {
                 gShaderFile.open(geometryPath);
                 std::stringstream gShaderStream;
                 gShaderStream << gShaderFile.rdbuf();
                 gShaderFile.close();
                 geometryCode = gShaderStream.str();
             }
         }
         catch (std::ifstream::failure e)
         {
             std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
         }
         const char* vShaderCode = vertexCode.c_str();
         const char* fShaderCode = fragmentCode.c_str();
         // 2. compile shaders
         unsigned int vertex, fragment;
         // vertex shader
         vertex = glCreateShader(GL_VERTEX_SHADER);
         glShaderSource(vertex, 1, &vShaderCode, NULL);
         glCompileShader(vertex);
         CheckCompileErrors(vertex, "VERTEX");
         // fragment Shader
         fragment = glCreateShader(GL_FRAGMENT_SHADER);
         glShaderSource(fragment, 1, &fShaderCode, NULL);
         glCompileShader(fragment);
         CheckCompileErrors(fragment, "FRAGMENT");
         // if geometry shader is given, compile geometry shader
         unsigned int geometry;
         if (geometryPath != nullptr)
         {
             const char* gShaderCode = geometryCode.c_str();
             geometry = glCreateShader(GL_GEOMETRY_SHADER);
             glShaderSource(geometry, 1, &gShaderCode, NULL);
             glCompileShader(geometry);
             CheckCompileErrors(geometry, "GEOMETRY");
         }
         // shader Program
         if (id)
         {
             glDeleteProgram(id);
         }

         id = glCreateProgram();
         glAttachShader(id, vertex);
         glAttachShader(id, fragment);
         if (geometryPath != nullptr)
             glAttachShader(id, geometry);
         glLinkProgram(id);
         CheckCompileErrors(id, "PROGRAM");
         // delete the shaders as they're linked into our program now and no longer necessery
         glDeleteShader(vertex);
         glDeleteShader(fragment);
         if (geometryPath != nullptr)
             glDeleteShader(geometry);


     }

	 void ShaderProgram::ImGui()
	 {
         Asset::ImGui();

	 }

    void ShaderProgram::Bind()
    {
        glUseProgram(id);
    }


     ShaderProgram::~ShaderProgram()
     {
         if (id)
         {
            glDeleteProgram(id);
         }
     }


     void ShaderProgram::SetUniform(const std::string& name, bool value) const
    {
        glUniform1i(glGetUniformLocation(id, name.c_str()), (int)value);
    }

     void ShaderProgram::SetUniform(const std::string& name, int value) const
    {
        glUniform1i(glGetUniformLocation(id, name.c_str()), value);
    }

     void ShaderProgram::SetUniform(const std::string& name, float value) const
    {
        glUniform1f(glGetUniformLocation(id, name.c_str()), value);
    }

     void ShaderProgram::SetUniform(const std::string& name, const glm::vec2& value) const
    {
        glUniform2fv(glGetUniformLocation(id, name.c_str()), 1, &value[0]);
    }

     void ShaderProgram::SetUniform(const std::string& name, float x, float y) const
    {
        glUniform2f(glGetUniformLocation(id, name.c_str()), x, y);
    }

     void ShaderProgram::SetUniform(const std::string& name, const glm::vec3& value) const
    {
        glUniform3fv(glGetUniformLocation(id, name.c_str()), 1, &value[0]);
    }

     void ShaderProgram::SetUniform(const std::string& name, float x, float y, float z) const
    {
        glUniform3f(glGetUniformLocation(id, name.c_str()), x, y, z);
    }

     void ShaderProgram::SetUniform(const std::string& name, const glm::vec4& value) const
    {
        glUniform4fv(glGetUniformLocation(id, name.c_str()), 1, &value[0]);
    }

     void ShaderProgram::SetUniform(const std::string& name, float x, float y, float z, float w)
    {
        glUniform4f(glGetUniformLocation(id, name.c_str()), x, y, z, w);
    }

     void ShaderProgram::SetUniform(const std::string& name, const glm::mat2& mat) const
    {
        glUniformMatrix2fv(glGetUniformLocation(id, name.c_str()), 1, GL_FALSE, &mat[0][0]);
    }

     void ShaderProgram::SetUniform(const std::string& name, const glm::mat3& mat) const
    {
        glUniformMatrix3fv(glGetUniformLocation(id, name.c_str()), 1, GL_FALSE, &mat[0][0]);
    }

     void ShaderProgram::SetUniform(const std::string& name, const glm::mat4& mat) const
    {
        glUniformMatrix4fv(glGetUniformLocation(id, name.c_str()), 1, GL_FALSE, &mat[0][0]);
    }

     void ShaderProgram::CheckCompileErrors(GLuint shader, std::string type)
    {
        GLint success;
        GLchar infoLog[1024];
        if (type != "PROGRAM")
        {
            glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
            if (!success)
            {
                glGetShaderInfoLog(shader, 1024, NULL, infoLog);
                std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
                std::cout<< "Vertex\t" << this->vPath << std::endl;
                std::cout<< "Fragment\t" << this->fPath << std::endl;
            }
        }
        else
        {
            glGetProgramiv(shader, GL_LINK_STATUS, &success);
            if (!success)
            {
                glGetProgramInfoLog(shader, 1024, NULL, infoLog);
                std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
            }
        }
    }
}
