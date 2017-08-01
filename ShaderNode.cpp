//
// Created by Göksu Güvendiren on 01/08/2017.
//

#include "ShaderNode.h"
#include "GL/GGL.h"

ppl::Blur::Blur(const gl::Window& win) : window(win)
{
    init_ggl(); // guzu gl
}

void ppl::Blur::create_program(const cv::Mat& image)
{
    gl::Shader vertex_shader("../shaders/default_vertex.glsl", gl::Shader::Type::Vertex);
    vertex_shader.Compile();

    gl::Shader fragment_shader("../shaders/blur.glsl", gl::Shader::Type::Fragment);
    fragment_shader.Compile();

    program.Init();
    program.Attach(vertex_shader);
    program.Attach(fragment_shader);
//    // Bind Fragment Data before linking the program !!
    program.BindFragData({"outColor"});
    program.Link();
    program.Use();
}

std::vector<ppl::any_t> ppl::Blur::Exec(std::vector<ppl::any_t> inputs)
{
    cv::Mat image   = boost::any_cast<cv::Mat>(inputs[0]);
    int kernel_size = boost::any_cast<int>(inputs[1]);

    init_gl_objects();
    create_program(image);

    // problematic :
    gl::Texture texture(image.cols, image.rows, image.data);
    program.LoadTexture(texture, "tex");

    auto frame_buffer = init_frame_buffer(image.cols, image.rows);

    init_attribs(program.ID());

    auto c_loc = program.SetUniform("cols", image.cols);
    auto r_loc = program.SetUniform("rows", image.rows);
    auto k_loc = program.SetUniform("kernel", kernel_size);

//    while(window.Alive())
    {
        program.Render(image.cols, image.rows, frame_buffer);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

//        window.Loop();
    }

    cv::Mat out(image.cols, image.rows, CV_8UC3);
    glPixelStorei(GL_PACK_ALIGNMENT, (out.step & 3) ? 1 : 4);
    glPixelStorei(GL_PACK_ROW_LENGTH, out.step / out.elemSize());

    glReadPixels(0, 0, out.cols, out.rows, GL_BGR, GL_UNSIGNED_BYTE, out.data);
    cv::flip(out, out, 0);

    return {boost::any(out)};
}

std::string ppl::Blur::Declare()
{
    return "hi";
}