#include "pch.h"
#include "cube.h"

#include "rendering/buffers/vertex_buffer.h"
#include "rendering/buffers/index_buffer.h"
#include "rendering/vertex_array.h"
#include "glad/glad.h"

namespace Split
{

	static void compute_point(const unsigned char i, float(&coords)[3])
	{
		float half_length = 0.5f;
		coords[0] = ((i & 3) == 3 || !(i & 3) ? -half_length : half_length);
		coords[1] = ((i & 2) ? -half_length : half_length);
		coords[2] = ((i < 4) ? half_length : -half_length);
	}

	std::shared_ptr<VertexArray> create_cube(void)
	{
		/* Generate cube verticies
		 */
		float coords[3];
		std::vector<float> verts;
		for (unsigned char i = 0; i < 8; i++)
		{
			compute_point(i, coords);
			verts.insert(verts.end(), std::begin(coords), std::end(coords));
		}
		auto vb = create_vertex_buffer(&verts[0], 12 * 3, GL_STATIC_DRAW);
		vb->attributes = { {"points", 3 } };

		/* Get cube indeces
		 */
		std::vector<unsigned int> indeces;
		for (auto& ui : base_indeces)
			indeces.push_back(ui);
		auto ib = create_index_buffer(&indeces[0], (unsigned int)indeces.size(), GL_STATIC_DRAW);

		return create_vertex_array(ib, vb);
	}

}
