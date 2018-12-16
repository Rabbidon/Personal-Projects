
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <string>
#include <vector>

struct Vertex
{
public:
	Vertex(const glm::vec3& pos)
	{
		this->pos = pos;
	}

	glm::vec3 pos;
};

class Mesh
{
public:
	Mesh(Vertex* vertices, unsigned int numVertices);

	void Draw();

	virtual ~Mesh();
protected:
private:
	void operator=(const Mesh& mesh) {}

	enum
	{
        POSITION_VB,

        NUM_BUFFERS
	};

	GLuint m_vertexArrayObject;
	GLuint m_vertexArrayBuffers[NUM_BUFFERS];
	unsigned int m_drawCount;
};


