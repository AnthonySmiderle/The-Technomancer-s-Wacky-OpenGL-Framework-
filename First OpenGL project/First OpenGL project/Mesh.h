#pragma once
#include "IO.h"
namespace Pm {
	class Mesh {
	public:
		Mesh() = default;
		~Mesh();

		bool loadMesh(const std::string& path);

		void unload();
		void draw();
		unsigned VBOverts = 0;
		unsigned VBOuvs = 0;
		unsigned VBOnormals = 0;
		unsigned VAO = 0;

		unsigned getFaces() const { return numFaces; }
		unsigned getVerts() const { return numVerts; }
	private:
		unsigned numFaces = 0;
		unsigned numVerts = 0;

	};
}