#include "Camera.h"
namespace Pm {

	Pm::Camera::Camera()
	{
	}

	glm::mat4 Camera::whereAreWeLooking() const
	{
		return glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
	}

	void Camera::doMouseMovement(float xoffset,float yoffset)
	{
		xoffset *= mouseSensitivity;
		yoffset *= mouseSensitivity;

		yaw += xoffset;
		pitch += yoffset;

		if (pitch > 89.0f)
			pitch = 89.0f;
		if (pitch < -89.0f)
			pitch = -89.0f;
		update();
	}

	void Camera::move(GLFWwindow* window,float movementSpeed)
	{
		if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
			cameraPos += movementSpeed * cameraFront;
		if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
			cameraPos -= movementSpeed * cameraFront;
		if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
			cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * movementSpeed;
		if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
			cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * movementSpeed;
	}

	void Camera::update()
	{
		glm::vec3 front;
		front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
		front.y = sin(glm::radians(pitch));
		front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
		cameraFront = glm::normalize(front);

		cameraRight = glm::normalize(glm::cross(cameraFront, cameraUp));  // Normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
		//cameraUp = glm::normalize(glm::cross(cameraRight, cameraFront));
	}


}
