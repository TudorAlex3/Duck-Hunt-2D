#include "object2D.h"

#include <vector>

#include "core/engine.h"
#include "utils/gl_utils.h"



Mesh* object2D::CreateIsoscelesTriangle(
    const std::string name,
    glm::vec3 leftBottomCorner,
    float base,
    float height,
    glm::vec3 color,
    bool fill)
{
    fill = true;
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(base, 0, 0), color),
        VertexFormat(corner + glm::vec3(base / 2, height, 0), color)
    };

    Mesh* triangle = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2 };

    triangle->InitFromData(vertices, indices);
    return triangle;
}

Mesh* object2D::CreateEquilateralTriangle(
    const std::string name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    fill = true;
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(length, 0, 0), color),
        VertexFormat(corner + glm::vec3(length / 2, length, 0), color)
    };

    Mesh* triangle = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2 };

    triangle->InitFromData(vertices, indices);
    return triangle;
}

Mesh* object2D::CreateRectangle(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    float height,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(length, 0, 0), color),
        VertexFormat(corner + glm::vec3(length, height, 0), color),
        VertexFormat(corner + glm::vec3(0, height, 0), color)
    };

    Mesh* rectangle = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3 };

    if (!fill) {
        rectangle->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    rectangle->InitFromData(vertices, indices);
    return rectangle;
}

Mesh* object2D::CreateCircle(
    const std::string& name,
    glm::vec3 center,
    float radius,
    glm::vec3 color,
    bool fill)
{
    std::vector<VertexFormat> vertices;
    vertices.push_back(VertexFormat(center, color));

    float delta = 2.0f * 3.14159f / 360;
    for (int i = 0; i < 360; i++) {
        vertices.push_back(VertexFormat(center + glm::vec3(radius * cos(i * delta), radius * sin(i * delta), 0), color));
    }

    Mesh* circle = new Mesh(name);
    std::vector<unsigned int> indices;

    // Add indices if only the outline of the circle is drawn.
    // Add indices for drawing triangles if it'a a full circle.

    if (!fill) {
        circle->SetDrawMode(GL_LINE_LOOP);
        for (int i = 1; i <= 360; i++) {
            indices.push_back(i);
        }
    }
    else {
        circle->SetDrawMode(GL_TRIANGLES);
        for (int i = 1; i < 360; i++) {
            indices.push_back(0);
            indices.push_back(i);
            indices.push_back(i + 1);
        }
        indices.push_back(0);
        indices.push_back(360);
        indices.push_back(1);
    }

    circle->InitFromData(vertices, indices);
    return circle;
}
