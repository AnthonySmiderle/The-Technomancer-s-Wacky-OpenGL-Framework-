#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
namespace Pm {
	class Camera {
	public:
		Camera();
		glm::mat4 whereAreWeLooking() const;
		
		void doMouseMovement(float xoffset,float yoffset);
		void move(GLFWwindow* window,float movementSpeed);

		glm::vec3& getPosition() { return cameraPos; }
		glm::vec3& getFront() { return cameraFront; }
	private:
		void update();

		float mouseSensitivity = 0.1f;
		bool firstMouse = true;
		float yaw = -90.0f;
		float pitch = 0.0f;

		glm::vec3 cameraRight = glm::vec3(0.0f, 0.0f, 0.0f);
		glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
		glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
		glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
	};
}