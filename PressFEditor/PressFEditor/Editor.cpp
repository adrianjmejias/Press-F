#include "Editor.h"


namespace PF
{
	std::vector<GameObject*> GetAsSeparateGameObjects(Model& model)
	{
		std::vector<GameObject*> gos;

		gos.reserve(model.meshes.size());

		for (auto& m : model.meshes)
		{
			GameObject* go{ new GameObject(m->name) };
			MeshRenderer* mr = go->AddComponent<MeshRenderer>();
			mr->mesh = m.get();
			mr->mat = m->defaultMaterial;
			gos.push_back(go);
		}
		return gos;
	}
}



void Editor::Init()
{
	engine.InitContext();
	////app.LoadShaders({});
	////PF::Scene scene;
	//engine.LoadModels(
	//		{
	//		"assets/models/cuboPower/simpleQuad.obj",
	//		//"assets/models/cuboPower/simpleCube.obj",
	//		//"assets/models/cuboPower/clown.obj",
	//		"assets/models/cuboPower/cuboPowerblend.obj"
	//	}
	//);
	//std::vector<PF::MeshRenderer&> mrs;

	//PF::ModelsManager& mm = engine.modelsManager;
	//PF::Model& model = mm.LoadAsset("../assets/models/cuboPower/simpleQuad.obj");

	//engine.load

	fbrowser.SetTitle("title");
	fbrowser.SetTypeFilters({ ".h", ".cpp" });




	engine.assetManager.LoadModel("quad", "../assets/models/big.obj");

	auto model = engine.assetManager.GetModel("quad");
	std::vector<PF::GameObject*> gos = PF::GetAsSeparateGameObjects(*model);


	for (auto go : gos)
	{
		engine.AddGameObject(go);
	}

	PF::GameObject& ts1 = engine.AddGameObject(new PF::GameObject("test subject 1"));
	ts1.AddComponent<Rotator>();


	//PF::ParticleSystem* ps = ts1.AddComponent<PF::ParticleSystem>();
	//ps->mesh = mesh;
	//ps->mat = mesh->defaultMaterial;





	PF::GameObject& ts2 = engine.AddGameObject(new PF::GameObject("test subject 2"));
	PF::Camera* cam = ts2.AddComponent<PF::Camera>();
	ts2.AddComponent<CameraController>();
	cam->Yaw = -5601.39600;
	cam->Pitch = -70.9999771;
	cam->transform->SetPosition({ 2.38617706 , 7.60761261, -1.88124359 });
	cam->updateCameraVectors();







	//json j = ts1.Serialize();

	//std::ofstream o("pretty.json");
	//o << j << std::endl;

	engine.Start();
	while (engine.running)
	{
		engine.LoopEvents();

		engine.InitRender();

		engine.LoopUpdate();

		engine.LoopImGui();

		LoopImGui();

		engine.EndRender();
	}

	engine.CleanContext();
}

void Editor::LoopImGui()
{
	auto io = ImGui::GetIO();


	ImGui::Begin("Editor window");

	ImGui::Text("asdasd");


	fbrowser.Display();

	if (fbrowser.HasSelected())
	{
		std::cout << "Selected filename" << fbrowser.GetSelected().string() << std::endl;
		fbrowser.ClearSelected();
	}
	ImGui::End();
}