#ifndef CUBE_H
#define CUBE_H

namespace Split
{

	class VertexArray;

	static const unsigned int base_indeces[36] = {
		0,1,3,1,2,3, // front face
		5,4,6,4,7,6, // back face
		4,5,0,5,1,0, // top face
		3,2,7,2,6,7, // bottom face
		1,5,2,5,6,2, // right face
		4,0,7,0,3,7  // left face
	};

	static void compute_point(const unsigned char i, float(&coords)[3]);

	std::shared_ptr<VertexArray> create_cube(void);

}

#endif /* CUBE_H */
