//
// Created by Göksu Güvendiren on 01/08/2017.
//

#include "ShaderNode.h"
#include "../GL/GGL.h"

//ppl::Blur::Blur(const gl::Window& win) : window(win)
//{
//    init_ggl(); // guzu gl
//}

ppl::BlurNode::BlurNode()
{
    init_ggl(); // guzu gl
    is_processed = false;
}

gl::Program program;

void ppl::BlurNode::create_program() const
{
    gl::Shader vertex_shader("../shaders/default_vertex.glsl", gl::Shader::Type::Vertex);
    vertex_shader.Compile();

    gl::Shader fragment_shader("../shaders/blur.glsl", gl::Shader::Type::Fragment);
    fragment_shader.Compile();

    program.Init();
    program.Attach(vertex_shader);
    program.Attach(fragment_shader);
    // Bind Fragment Data before linking the program !!
    program.BindFragData({"outColor"});
    program.Link();
    program.Use();
}

int x = 0;

std::vector<ppl::any_t> ppl::BlurNode::Exec(std::vector<ppl::any_t> inputs)
{
    std::cerr << Name() << '\n';

    gl::Texture texture   = boost::any_cast<gl::Texture>(inputs[0]);
    int kernel_size = 2; //boost::any_cast<int>(inputs[1]);

    init_gl_objects();
    create_program();

    program.LoadTexture(texture, "tex");

    auto buffer = init_frame_buffer(texture.cols(), texture.rows());
    auto frame_buffer = buffer.first;
    auto renderedTexture = buffer.second;

    init_attribs(program.ID());

    auto c_loc = program.SetUniform("cols", texture.cols());
    auto r_loc = program.SetUniform("rows", texture.rows());
    auto k_loc = program.SetUniform("kernel", kernel_size);

    program.Render(texture.cols(), texture.rows(), frame_buffer);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

//    cv::Mat out(texture.cols(), texture.rows(), CV_8UC3);
//    glPixelStorei(GL_PACK_ALIGNMENT, (out.step & 3) ? 1 : 4);
//    glPixelStorei(GL_PACK_ROW_LENGTH, out.step / out.elemSize());
//
//    glReadPixels(0, 0, out.cols, out.rows, GL_RGB, GL_UNSIGNED_BYTE, out.data);
//    cv::flip(out, out, 0);
//
//    cv::imwrite("guzuya_output" + std::to_string(x) + ".png", out);
//    x++;

    is_processed = true;

    return {boost::any(renderedTexture)};
}

std::string ppl::BlurNode::Declare() const
{
    return "hi";
}
