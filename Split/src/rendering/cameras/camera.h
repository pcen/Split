#ifndef CAMERA_H
#define CAMERA_H

namespace Split
{

	class Camera
	{
	public:
		virtual ~Camera() {}
		virtual void update(double deltatime) = 0;
		virtual glm::mat4& get_matrix(void) = 0;

	protected:
		Camera() {}

	private:

	};

}

#endif /* CAMERA_H */
