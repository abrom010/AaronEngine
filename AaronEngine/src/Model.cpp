#include "Model.h"

#include <iostream>

namespace AaronEngine {
	Model::Model(std::string filePath, bool gammaCorrection)
		: gammaCorrection(gammaCorrection)
	{
        //Assimp::Importer import;
        /*const aiScene* scene = import.ReadFile(filePath, aiProcess_Triangulate | aiProcess_FlipUVs);

        if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
        {
            std::cout << "ERROR::ASSIMP::" << import.GetErrorString() << std::endl;
            return;
        }*/
	}


}