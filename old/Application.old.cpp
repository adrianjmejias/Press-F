//#include "Application.h"
//
//extern double deltaTime = 0;
//extern unsigned int GLOBAL_ID = 1;
////extern Camera* mainCamera = nullptr;
//enum class Dirty;
//
//
//
//void ImGuiTransform(Transform &t) {
//	if (ImGui::SliderFloat3("Rotation", &t.rotation[0], -360.f, 360.f)) {
//		t.SetDirty(Dirty::Model);
//	}
//	if (ImGui::SliderFloat3("Scale", &t.scale[0], -20, 20)) {
//		t.SetDirty(Dirty::Model);
//	}
//	if (ImGui::SliderFloat3("Position", &t.position[0], -20, 20)) {
//		t.SetDirty(Dirty::Model);
//	}
//	//if (ImGui::("Rotation", &t.rotation[0])) {
//	//	t.SetDirty(Dirty::Model);
//	//}
//}
//
//static void Traverse(const std::vector<GameObject*> objects, std::function<void(GameObject*)> beforefgo, std::function<void(GameObject*)> afterfgo, std::function<void(Component*)> fcomp) {
//	std::queue<GameObject*, std::deque<GameObject *>> q(std::deque<GameObject*>(objects.begin(), objects.end()));
//	while (!q.empty()) {
//		GameObject *go = q.front();
//		q.pop();
//		PF_ASSERT(go && "game object is null");
//
//		beforefgo(go);
//		for (Component* comp : go->components) {
//			PF_ASSERT(comp && "component is null");
//
//			fcomp(comp);
//		}
//		afterfgo(go);
//
//		for (Transform* t : go->transform.children) {
//			PF_ASSERT(t && "Children is null");
//
//			q.push(&t->gameObject);
//		}
//	}
//}
//
//void Application::Setup()
//{
//	spdlog::set_pattern("[%M:%S %z] [%^%v%$]");
//
//	
//	SetupScene();
//
//
//
//	/*for (Model *model : models) {
//		for (Mesh &mesh : *model) {
//			auto matName = mesh.mat.name;
//			if (materialsLoaded.find(matName) == end(materialsLoaded)) {
//				materialsLoaded[matName] = &mesh.mat;
//			}
//		}
//	}*/
//
//
//
//	glEnable(GL_DEPTH_TEST);
//	glEnable(GL_BLEND);
//	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//	// Sets up shit. maybe not the best way but it's what came to me
//
//	/*Traverse(rootNodes,
//		[](GameObject* go) {
//	},
//		[](GameObject* go) {
//	},
//		[&](Component* comp) {
//		Steal(comp);
//	}
//	);*/
//
//}
//
//void Application::SetupScene()
//{
//	//depthFB = FrameBuffer::GetShadowBuffer(1024, 1024);
//	//cubeMap = new CubeMap({
//	//"assets/skybox/right.jpg",
//	//"assets/skybox/left.jpg",
//	//"assets/skybox/top.jpg",
//	//"assets/skybox/bottom.jpg",
//	//"assets/skybox/front.jpg",
//	//"assets/skybox/back.jpg"
//	//	});
//	//cubeMap->shader = shaders[6];
//
//	//depthPlaneShader = shaders[11];
//
//	//float quadVertices[] = {
//	//	// positions        // texture Coords
//	//	-1.0f,  1.0f, 0.0f, 0.0f, 1.0f,
//	//	-1.0f, -1.0f, 0.0f, 0.0f, 0.0f,
//	//	 1.0f,  1.0f, 0.0f, 1.0f, 1.0f,
//	//	 1.0f, -1.0f, 0.0f, 1.0f, 0.0f,
//	//};
//	//// setup plane VAO
//	//glGenVertexArrays(1, &VAO_PLANE);
//	//glGenBuffers(1, &VBO_PLANE);
//	//glBindVertexArray(VAO_PLANE);
//	//glBindBuffer(GL_ARRAY_BUFFER, VBO_PLANE);
//	//glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), &quadVertices, GL_STATIC_DRAW);
//	//glEnableVertexAttribArray(0);
//	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
//	//glEnableVertexAttribArray(1);
//	//glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
//
//
//
//	//{
//	//	GameObject *go = new GameObject();
//	//	fc = go->AddComponent < FlyingController >();
//	//	go->AddComponent < Camera >();
//	//	//cam = &go->AddComponent<CameraGL>();
//
//	//	go->transform.SetPosition(0, 0, -20);
//	//	rootNodes.push_back(go);
//
//	//}
//	//Mesh &lightMesh = lightsModel->at(0);
//	//{
//	//	GameObject *go = new GameObject();
//	//	go->AddComponent < Light >(LightType::DIRECTIONAL);
//	//	go->AddComponent < Camera >();
//	//	MeshRenderer *ren = go->AddComponent<MeshRenderer>(&lightMesh);
//	//	lightMesh.push_back(ren);
//	//	go->transform.SetPosition(-7.f, 12.74f, -86.2f);
//	//	go->transform.SetRotation(346.8f, 359.2f, 0.f);
//	//	rootNodes.push_back(go);
//	//}
//
//	//{
//	//	GameObject *go = new GameObject();
//	//	go->AddComponent < Light >(LightType::POINT);
//	//	MeshRenderer *ren = go->AddComponent<MeshRenderer>(&lightMesh);
//	//	lightMesh.push_back(ren);
//
//	//	go->transform.SetPosition(0, -10, 0);
//	//	rootNodes.push_back(go);
//	//}
//
//
//	//for (Model *model : models) {
//	//	GameObject *papa = new GameObject();
//	//	for (Mesh &mesh : *model) {
//	//		GameObject *go = new GameObject();
//	//		MeshRenderer *ren = go->AddComponent<MeshRenderer>(&mesh);
//	//		mesh.push_back(ren);
//
//	//		go->transform.SetPosition(0, 0, 0);
//	//		go->transform.SetScale(3, 3, 3);
//	//		go->transform.Rotate(0, 90, 0);
//	//		go->transform.SetParent(&papa->transform);
//	//		//go->transform.SetPosition(glm::ballRand(3.f) + 2.f);
//
//	//	}
//	//	rootNodes.push_back(papa);
//	//}
//}
////

//void Application::LoadShaders(const std::vector<std::tuple<std::string, std::string>>& shaderPaths)
//{
//	const std::string baseShaderFolder = "assets/shaders/";
//	for (int ii = 0; ii < shaderPaths.size(); ii++)
//	{
//		auto tupleName = shaderPaths[ii];
//
//		auto vertName = std::get<0>(tupleName);
//		auto fragName = std::get<1>(tupleName);
//
//		Shader *vert = nullptr;
//		Shader *frag = nullptr;
//
//	/*	try
//		{
//			vert = shadersLoaded.at(vertName);
//		}
//		catch (const std::exception&)
//		{
//			vert = Shader::FromPath(baseShaderFolder + vertName, GL_VERTEX_SHADER);
//			shadersLoaded[vertName] = vert;
//		}
//
//		try
//		{
//			frag = shadersLoaded.at(fragName);
//		}
//		catch (const std::exception&)
//		{
//			frag = Shader::FromPath(baseShaderFolder + fragName, GL_FRAGMENT_SHADER);
//			shadersLoaded[fragName] = frag;
//		}*/
//
//		shaders.push_back(new ShaderProgram({ vert, frag }));
//	}
//}
//

//
//
//void Application::LoopMain()
//{
//	while (running) {
//		//std::cout << "looping";
//		glViewport(0, 0, win_width, win_heigth);
//
//
//		LoopEvents();
//
//		LoopUpdate();
//
//		LoopRender();
//
//		LoopUI();
//
//		SDL_GL_SwapWindow(win);
//
//		NOW = SDL_GetPerformanceCounter();
//		deltaTime = (double)((NOW - LAST) / (double)SDL_GetPerformanceFrequency());
//		SDL_GetMouseState(&mouse_deltaX, &mouse_deltaY);
//		mouse_deltaX -= mouse_lastPosX;
//		mouse_deltaY -= mouse_lastPosY;
//		mouse_deltaY *= -1;
//	}
//}
//


//void Application::LoopUI()
//{
//
//	//ImGui_ImplOpenGL3_NewFrame();
//	//ImGui_ImplSDL2_NewFrame(win);
//	//ImGui::NewFrame();
//
//
//	//ImGui::ShowDemoWindow(&show_demo_window);
//
//	//ImGui::Begin("Materials");
//	//for (auto pair : materialsLoaded)
//	//{
//	//	const std::string& matName = pair.first;
//	//	Material& mat = *pair.second;
//
//	//	if ((ImGui::TreeNode(matName.c_str())))
//	//	{
//	//		//ImGui::SliderFloat4("kD", &mat.kD[0], 0.f,1.f);	
//	//		ImGui::ColorEdit3("kD##2f", (float*)&mat.kD[0], ImGuiColorEditFlags_Float);
//	//		ImGui::ColorEdit3("kA##2f", (float*)&mat.kS[0], ImGuiColorEditFlags_Float);
//	//		ImGui::ColorEdit3("kS##2f", (float*)&mat.kA[0], ImGuiColorEditFlags_Float);
//	//		ImGui::SliderFloat("Ni", &mat.Ni, 0.f, 1.f);
//	//		ImGui::SliderFloat("Ns", &mat.Ns, 0.f, 3.f);
//	//		ImGui::SliderInt("Shader", &mat.illum, 0, (int)(shaders.size() - 1));
//	//		//mat.illum
//
//
//	//		switch (mat.illum)
//	//		{
//	//		case 3:
//	//			ImGui::SliderFloat("IOR Material", &mat.IOR, 0.f, 3.f);
//	//			ImGui::SliderFloat("IOR Air", &IOR_BG, 0.f, 3.f);
//	//			break;
//	//		case 8:
//	//			ImGui::SliderFloat("HeightScale", &heightScale, 0.f, 10.f);
//	//			ImGui::SliderFloat("MinLayers", &minLayers, 6.f, maxLayers);
//	//			ImGui::SliderFloat("MaxLayers", &maxLayers, minLayers, 400.f);
//
//	//			break;
//	//		default:
//	//			break;
//	//		}
//
//
//
//	//		ImGui::TreePop();
//	//	}
//	//}
//	//ImGui::End();
//
//
//	//ImGui::Begin("Lights");
//	//{
//	//	
//	//	Transform &camTransform = *mainCamera->transform;
//	//	ImGui::Text("Camera transform");
//	//	ImGuiTransform(camTransform);
//
//
//
//
//	//	ImGui::SliderFloat4("orthoSize", &orthoSides[0], -100, 100);
//	//	ImGui::SliderFloat2("clipping", &clippingPlane[0], 1, 600);
//
//
//	//	for (Light* light : LIGHTS) {
//	//		if (ImGui::TreeNode(light->gameObject->name.c_str())) {
//
//	//			ImGuiTransform(*light->transform);
//
//	//			ImGui::Checkbox("isOn", reinterpret_cast<bool*>(&light->enabled));
//	//			ImGui::ColorEdit4("kD##2f", (float*)&light->kD[0], ImGuiColorEditFlags_Float);
//	//			ImGui::ColorEdit4("kS##2f", (float*)&light->kS[0], ImGuiColorEditFlags_Float);
//	//			ImGui::ColorEdit4("kA##2f", (float*)&light->kA[0], ImGuiColorEditFlags_Float);
//	//			const char* types[] = { "Point","Directional", "Spotlight" };
//	//			ImGui::Combo("Type", reinterpret_cast<int*>(&light->type), types, IM_ARRAYSIZE(types));
//
//	//			switch (light->type)
//	//			{
//	//			case LightType::SPOTLIGHT:
//	//				ImGui::SliderFloat("InnerAngle", &light->innerAngle, 5.f, light->outterAngle);
//	//				ImGui::SliderFloat("OutterAngle", &light->outterAngle, light->innerAngle, 90.f);
//	//				//falls
//	//			case LightType::POINT:
//	//				ImGui::SliderFloat3("attenuation", &light->attenuation[0], 0, 3);
//
//
//	//			default:
//	//				break;
//	//			}
//
//
//
//	//			ImGui::TreePop();
//	//		}
//	//	}
//	//}
//	//ImGui::End();
//
//
//	////ImGui::Begin("GameObjects");
//	////Traverse(rootNodes,
//	////	[](GameObject* go) {
//	////	ImGui::TreeNode(go->name.c_str());
//	////},
//	////	[](GameObject* go) {
//	////	ImGui::TreePop();
//	////},
//	////	[](Component* comp) {
//	////	
//	////	if (ImGui::TreeNode("ssss")) {
//	////		ImGui::TreePop();
//	////	}
//	////}
//	////);
//	////ImGui::End();
//
//
//	//bool showSelected = actGO != nullptr;
//	//ImGui::Begin("Selected Object", &showSelected);
//	//{
//	//	//ImGui::LabelText(actGO->name.c_str(),);
//
//	//}
//	//ImGui::End();
//
//
//
//	// Rendering
//
//}
//
//void Application::LoopUpdate()
//{
//	//Traverse(rootNodes,
//	//	[](GameObject* go) {},
//	//	[](GameObject* go) {},
//	//	[](Component* comp) {comp->Update(); }
//	//);
//}
//
//void Application::LoopRender()
//{
////	std::vector<const Mesh *> NonTransparentMeshes;
////	std::vector<const MeshRenderer *> transparentMeshes;
////	const Camera& cam = *cameras[actCam];
////	Transform &camTransform = *cam.transform;
////	const Vec3& camPos = camTransform.GetPosition();
////	const Mat4& projection = Transform::GetProjection(camTransform, true, win_width / static_cast<float>(win_width));
////	const Mat4& view = Transform::GetView(camTransform);
////
////	bool camDirty =  camTransform.TryGetClean();
////
////	Traverse(rootNodes,
////		[](GameObject* go) {},
////		[&](GameObject* go) {
////			if (camDirty || go->transform.TryGetClean()) {
////				Mat4 acum = go->transform.GetAccumulated();
////				go->transform.MVP = projection * view * acum;
////				go->transform.normalMatrix = glm::mat3(glm::transpose(glm::inverse(acum * view)));
////			}
////		},
////		[](Component* comp) {}
////		);
////
////
////		Transform &lightTransform = *LIGHTS[0]->transform;
////		Mat4 ViewProjection = glm::ortho(orthoSides[0], orthoSides[1], orthoSides[2], orthoSides[3], clippingPlane[0], clippingPlane[1]);//Transform::GetProjection(lightTransform, false, win_width / static_cast<float>(win_heigth));
////		ViewProjection = ViewProjection * Transform::GetView(lightTransform);
////		Texture &shadowTex = depthFB->texture;
////		ShaderProgram &depthShader = *shaders[4];
////
////
////		glViewport(0, 0, shadowTex.width, shadowTex.height);
////		glBindFramebuffer(GL_FRAMEBUFFER, depthFB->id);
////		glClear(GL_DEPTH_BUFFER_BIT);
////
////		depthShader.Use();
////		SET_UNIFORM(depthShader, ViewProjection);
////		
////
////		glActiveTexture(GL_TEXTURE0);
////		glBindTexture(GL_TEXTURE_2D, depthFB->texture.id);
////		
////
////		for (const Model* model : (models)) 
////		{
////			for (const Mesh& mesh : *model) 
////			{
////				glBindVertexArray(mesh.VAO);
////
////				for (auto ren : mesh) {
////					Mat4 model = ren->transform->GetAccumulated();
////					SET_UNIFORM(depthShader, model);
////					glDrawElements(GL_TRIANGLES, mesh.nElem, GL_UNSIGNED_INT, 0);
////				}
////				glBindVertexArray(0);
////			}
////		}
////		glBindFramebuffer(GL_FRAMEBUFFER, 0);
////
////
////
////	glViewport(0, 0, win_width, win_heigth);
////	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
////
////	for (const Model* model : (models)) {
////
////		for (const Mesh& mesh : *model) {
////			if (mesh.mat.illum == 1) // 1 transparent shader index
////			{
////				for (const MeshRenderer * mr : mesh) {
////					transparentMeshes.push_back(mr);
////				}
////			}
////			else
////			{
////				NonTransparentMeshes.push_back(&mesh);
////			}
////		}
////	}
////
////
////
////#ifdef TRANSPARENCY_ON
////	std::sort(begin(transparentMeshes), end(transparentMeshes), [&](const MeshRenderer* a, const MeshRenderer* b) {
////		float distCamToA = a->transform.GetPosition() - camPos;
////		float distCamToB = b->transform.GetPosition() - camPos;
////
////		//no saco sqrt sino que hago esto. no me importa el valor exacto de distancia
////		return distCamToA * distCamToA < distCamToB*distCamToB;
////	});
////#endif // TRANSPARENCY_ON
////
////	{
////
////
////		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
////		glClearColor(bgColor.x, bgColor.y, bgColor.z, bgColor.a);
////		if (renderScene)
////		{
////
////			DrawObjects(view, projection, NonTransparentMeshes, [&](const ShaderProgram& shader, const Material& MAT)->bool {
////
////				if (shader.usesMaterial) {
////					SET_UNIFORM(shader, MAT.kA);
////					SET_UNIFORM(shader, MAT.kD);
////					SET_UNIFORM(shader, MAT.kS);
////					SET_UNIFORM(shader, MAT.Ns);
////					SET_UNIFORM(shader, MAT.Ni);
////					SET_UNIFORM(shader, MAT.IOR);
////					SET_UNIFORM(shader, heightScale);
////
////					SET_UNIFORM(shader, minLayers);
////					SET_UNIFORM(shader, maxLayers);
////
////					shader.SetUniform("IOR", IOR_BG);
////				}
////
////				glActiveTexture(GL_TEXTURE5);
////				glBindTexture(GL_TEXTURE_CUBE_MAP, cubeMap->textureID);
////
////				if (shader.usesTextures)
////				{
////					GLCALL(glUniform1i(glGetUniformLocation(shader.id, "tex_kD"), 0));
////					GLCALL(glUniform1i(glGetUniformLocation(shader.id, "tex_Bump"), 1));
////					GLCALL(glUniform1i(glGetUniformLocation(shader.id, "tex_displacement"), 2));
////					GLCALL(glUniform1i(glGetUniformLocation(shader.id, "depthMap"), 3));
////					if (MAT.smap_Kd != nullptr)
////					{
////						GLCALL(glActiveTexture(GL_TEXTURE0));
////						GLCALL(glBindTexture(GL_TEXTURE_2D, MAT.smap_Kd->id));
////					}
////
////					if (MAT.smap_bump != nullptr)
////					{
////						GLCALL(glActiveTexture(GL_TEXTURE1));
////						GLCALL(glBindTexture(GL_TEXTURE_2D, MAT.smap_bump->id));
////					}
////
////					if (MAT.smap_d != nullptr)
////					{
////						GLCALL(glActiveTexture(GL_TEXTURE2));
////						GLCALL(glBindTexture(GL_TEXTURE_2D, MAT.smap_d->id));
////					}
////				}
////
////				GLCALL(glActiveTexture(GL_TEXTURE3));
////				GLCALL(glBindTexture(GL_TEXTURE_2D, depthFB->texture.id));
////				shader.SetUniform("depthMap" ,3);
////
////				if (shader.lit)
////				{
////					int lightsPlaced{ 0 };
////					for (Light* light : LIGHTS) {
////						PF_ASSERT(light && "Light is null");
////						light->Bind(lightsPlaced, shader);
////					}
////				}
////
////				if (shader.viewDependant) {
////					GLCALL(shader.SetUniform("viewPos", cam.transform->GetPosition()));
////				}
////
////				if (shader.MVP) {
////					SET_UNIFORM(shader, projection);
////					SET_UNIFORM(shader, view);
////				}
////
////				return true;
////			});
////
////			DrawObjects(view, projection, transparentMeshes, [&](const ShaderProgram& shader, const Material& MAT, const MeshRenderer& meshRen)-> bool {
////
////				if (MAT.smap_Kd)
////				{
////					glActiveTexture(GL_TEXTURE1);
////					glBindTexture(GL_TEXTURE_2D, MAT.smap_Kd->id);
////					shader.SetUniform("tex_kD", 1);
////				}
////				else
////				{
////					PF_ASSERT("ALL TRANSPARENT MATERIALS MUST HAVE A TEXTURE");
////				}
////
////				return true;
////			});
////
////
////			if (actCam == 0) {
////				std::vector<const MeshRenderer*> LightMeshes;
////
////				Mesh& renderers = (*lightsModel)[0];
////				for (const MeshRenderer* ren : renderers) {
////					LightMeshes.push_back(ren);
////				}
////				// Draw lights
////
////				int ii = 0;
////				DrawObjects(view, projection, LightMeshes, [&](const ShaderProgram& shader, const Material& MAT, const MeshRenderer& meshRen)->bool {
////					Light * light = LIGHTS[ii];
////
////					bool isOn = light->enabled != 0;
////					Color kD = light->kD;
////
////					SET_UNIFORM(shader, kD);
////					SET_UNIFORM(shader, isOn);
////					SET_UNIFORM(shader, projection);
////					SET_UNIFORM(shader, view);
////
////					ii++;
////					return true;
////				});
////
////			}
////
////			glDepthFunc(GL_LEQUAL);
////			{
////				cubeMap->shader->Use();
////				ShaderProgram &shader = *cubeMap->shader;
////				glm::mat4 viewSkybox = glm::mat4(glm::mat3(view));
////
////				shader.SetUniform("view", viewSkybox);
////				SET_UNIFORM(shader, projection);
////
////
////				glBindVertexArray(cubeMap->skyboxVAO);
////				{
////					glActiveTexture(GL_TEXTURE0);
////					glBindTexture(GL_TEXTURE_CUBE_MAP, cubeMap->textureID);
////
////					glDrawArrays(GL_TRIANGLES, 0, 36);
////				}
////				glBindVertexArray(0);
////
////
////			}
////			glDepthFunc(GL_LESS);
////
////		}
////
////
////
////		if (this->renderPlane) 
////		{
////			depthPlaneShader->Use();
////			GLCALL(glBindVertexArray(VAO_PLANE));
////			{
////				GLCALL(glActiveTexture(GL_TEXTURE0));
////				GLCALL(glBindTexture(GL_TEXTURE_2D, shadowTex.id));
////				GLCALL(depthPlaneShader->SetUniform("depthMap", 0));
////
////				GLCALL(glDrawArrays(GL_TRIANGLE_STRIP, 0, 4));
////			}
////			GLCALL(glBindVertexArray(0));
////		}
//
////}
//
//
//}
//
////void Application::DrawObjects(const Mat4 & view, const Mat4 & projection, std::vector<const Mesh*> meshes, std::function<bool(const ShaderProgram&shader, const Material&MAT)> PreReqs)
////{
////
////	/*auto meshesToRender = meshes;
////	for (const Mesh * const mesh : meshesToRender) {
////		const Material &MAT = mesh->mat;
////		const ShaderProgram &shader = *shaders[MAT.illum];
////
////		shader.Use();
////		GLCALL(glBindVertexArray(mesh->VAO));
////
////		PreReqs(shader, MAT);
////
////		for (auto obj : *mesh) {
////			PF_ASSERT(obj && "Renderer is null");
////			const Mat4 &model = obj->transform->GetAccumulated();
////			const glm::mat3 &normalMatrix = obj->transform->normalMatrix;
////
////			SET_UNIFORM(shader, model);
////			SET_UNIFORM(shader, normalMatrix);
////
////			GLCALL(glDrawElements(GL_TRIANGLES, mesh->nElem, GL_UNSIGNED_INT, 0));
////		}
////	}
////	GLCALL(glBindVertexArray(0));*/
////
////}
//

//
//inline Model * Application::GLCreate(objl::Loader & fullModel) {
//	Model * m = new Model();
//	Model &model = *m;
//	//data transform
//	//std::vector<Vertex> vertex;
//	//vertex.reserve(fullModel.LoadedVertices.size());
//	//for (const objl::Vertex& oVertex : fullModel.LoadedVertices) {
//	//	vertex.push_back(Vertex(oVertex));
//	//}
//
//	GLsizei totalIndices = 0;
//	model.reserve(fullModel.LoadedMeshes.size());
//
//
//
//
//
//	std::vector<Vertex> vertex{begin(fullModel.LoadedVertices), end(fullModel.LoadedVertices)};
//
//	std::vector<Vec3> tanPerFace;
//	tanPerFace.reserve(fullModel.LoadedIndices.size() / 3);
//
//	std::vector<std::vector<size_t> > vertexContrib{ vertex.size(), std::vector<size_t>() };
//
//	for (size_t iiFace = 0, iiReal = 0; iiReal < fullModel.LoadedIndices.size() - 2; iiFace++, iiReal += 3)
//	{
//		const int idx_a = fullModel.LoadedIndices[iiReal];
//		const int idx_b = fullModel.LoadedIndices[iiReal + 1];
//		const int idx_c = fullModel.LoadedIndices[iiReal + 2];
//
//		const Vertex &v_1 = vertex[idx_a];
//		const Vertex &v_2 = vertex[idx_b];
//		const Vertex &v_3 = vertex[idx_c];
//
//
//		// hago esto por legibilidad
//		const Vec3 &u{ v_1.uv[0],v_2.uv[0],v_3.uv[0] };
//		const Vec3 &v{ v_1.uv[1],v_2.uv[1],v_3.uv[1] };
//		const Vec3 p[3]{ v_1.pos,v_2.pos ,v_3.pos };
//
//
//		const float v20 = v[2] - v[0];
//		const float v10 = v[1] - v[0];
//
//		const float u10 = u[1] - u[0];
//		const float u20 = u[2] - u[0];
//
//		const Vec3 p10 = p[1] - p[0];
//		const Vec3 p20 = p[2] - p[0];
//
//
//		const Vec3 tan(((v20*p10) - (v10 * p20)) / ((u10*v20) - (v10*u20)));
//
//
//		tanPerFace.push_back(tan);
//
//		vertexContrib[idx_a].push_back(iiFace);
//		vertexContrib[idx_b].push_back(iiFace);
//		vertexContrib[idx_c].push_back(iiFace);
//	}
//
//	for (size_t ii = 0; ii < vertexContrib.size(); ii++)
//	{
//		Vec3 promTan{ 0,0,0 };
//
//
//		for (size_t indexFace : vertexContrib[ii])
//		{
//			promTan += tanPerFace[indexFace];
//		}
//
//		vertex[ii].tan = glm::normalize(promTan / static_cast<float>(vertexContrib[ii].size()));
//	}
//
//	for (int ii = 0; ii < fullModel.LoadedMeshes.size(); ii++) {
//		objl::Mesh& objlMesh = fullModel.LoadedMeshes[ii];
//		Mesh myMesh;
//		myMesh.name = objlMesh.MeshName;
//
//		std::vector<Vertex> meshVertex{begin(objlMesh.Vertices), end(objlMesh.Vertices) };
//		
//
//		myMesh.mat = objlMesh.MeshMaterial;
//		myMesh.nElem = static_cast<GLsizei>(objlMesh.Indices.size());
//		myMesh.offset = totalIndices;
//
//		totalIndices += myMesh.nElem;
//
//		GLCALL(glGenVertexArrays(1, &myMesh.VAO));
//		GLCALL(glGenBuffers(1, &myMesh.EBO));
//		GLCALL(glGenBuffers(1, &myMesh.VBO));
//
//		GLCALL(glBindVertexArray(myMesh.VAO));
//		{
//			GLCALL(glBindBuffer(GL_ARRAY_BUFFER, myMesh.VBO));
//			GLCALL(glBufferData(GL_ARRAY_BUFFER, meshVertex.size() * sizeof(Vertex), meshVertex.data(), GL_STATIC_DRAW));
//
//			GLCALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, myMesh.EBO));
//			GLCALL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, objlMesh.Indices.size() * sizeof(unsigned int), objlMesh.Indices.data(), GL_STATIC_DRAW));
//
//			{
//				GLCALL(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, pos)));
//				GLCALL(glEnableVertexAttribArray(0));
//
//				GLCALL(glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal)));
//				GLCALL(glEnableVertexAttribArray(1));
//
//				GLCALL(glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, uv)));
//				GLCALL(glEnableVertexAttribArray(2));
//
//				GLCALL(glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, tan)));
//				GLCALL(glEnableVertexAttribArray(3));
//
//			}
//
//		}
//		GLCALL(glBindVertexArray(0));
//		model.push_back(myMesh);
//
//	}
//	
//	return m;
//}
//
//void Application::Steal(Component *comp)
//{
//	//if (Light* l = dynamic_cast<Light*>(comp)) {
//	//	LIGHTS.push_back(l);
//	//}
//
//	//if (Camera * cam = dynamic_cast<Camera*>(comp)) {
//	//	if (cameras.size() < 1) {
//	//		mainCamera = cam;
//	//		mainCamera->power = 1;
//	//	}
//	//	cameras.push_back(cam);
//	//}
//
//	//if (MeshRenderer* ren = dynamic_cast<MeshRenderer*>(comp)) {
//	//	renderers.push_back(ren);
//	//}
//}
////
////inline void Application::DrawObjects(const Mat4 & view, const Mat4 & projection, std::vector<const MeshRenderer*> meshes, std::function<bool(const ShaderProgram&shader, const Material&MAT, const MeshRenderer&mesh)> PreReqs)
////{
////	auto meshesToRender = meshes;
////	for (const MeshRenderer * const meshRen : meshesToRender) {
////
////		const Mesh * mesh = meshRen->mesh;
////		const Material &MAT = mesh->mat;
////		const ShaderProgram &shader = *shaders[MAT.illum];
////
////		shader.Use();
////		GLCALL(glBindVertexArray(mesh->VAO));
////
////
////		if (PreReqs(shader, MAT, *meshRen)) {
////
////			const Mat4 &MVP = meshRen->transform->MVP;
////			SET_UNIFORM(shader, MVP);
////			GLCALL(glDrawElements(GL_TRIANGLES, mesh->nElem, GL_UNSIGNED_INT, 0));
////		}
////
////	}
////	GLCALL(glBindVertexArray(0));
////
////}
//

