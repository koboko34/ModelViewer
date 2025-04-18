#include "ImGuiManager.h"

#include "Application.h"
#include "PostProcess.h"
#include "GameObject.h"

static int s_SelectedId = -1;

ImGuiManager::ImGuiManager()
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGui::StyleColorsDark();
}

ImGuiManager::~ImGuiManager()
{
	ImGui::DestroyContext();
}

void ImGuiManager::RenderPostProcessWindow()
{
	Application* pApp = Application::GetSingletonPtr();
	auto& PostProcesses = pApp->GetPostProcesses();
	
	if (ImGui::Begin("Post Processes") && !PostProcesses.empty())
	{
		for (int i = 0; i < PostProcesses.size(); i++)
		{
			if (i != 0)
			{
				ImGui::Dummy(ImVec2(0.f, 10.f));
			}

			ImGui::PushID(i);
			ImGui::Checkbox("", &PostProcesses[i]->GetIsActive());
			ImGui::SameLine();
			if (ImGui::CollapsingHeader(PostProcesses[i]->GetName().c_str()))
			{
				PostProcesses[i]->RenderControls();
			}
			ImGui::PopID();
		}

		ImGui::Dummy(ImVec2(0.f, 20.f));
		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
	}
	ImGui::End();
}

void ImGuiManager::RenderWorldHierarchyWindow()
{
	Application* pApp = Application::GetSingletonPtr();
	auto& GameObjects = pApp->GetGameObjects();
	
	ImGui::Begin("World Hierarchy");

	ImGui::BeginChild("##", ImVec2(0, 250), ImGuiChildFlags_Border, ImGuiWindowFlags_HorizontalScrollbar);
	for (int i = 0; i < GameObjects.size(); i++)
	{
		if (ImGui::Selectable(GameObjects[i]->GetName().c_str(), s_SelectedId == i))
		{
			s_SelectedId = i;
		}
	}
	ImGui::EndChild();

	ImGui::Dummy(ImVec2(0.f, 10.f));

	if (s_SelectedId >= 0)
	{
		GameObjects[s_SelectedId]->RenderControls();
		ImGui::Dummy(ImVec2(0.f, 5.f));
		ImGui::Separator();
		ImGui::Dummy(ImVec2(0.f, 10.f));

		for (auto& Comp : GameObjects[s_SelectedId]->GetComponents())
		{
			Comp->RenderControls();
			ImGui::Dummy(ImVec2(0.f, 5.f));
			ImGui::Separator();
			ImGui::Dummy(ImVec2(0.f, 10.f));
		}
	}

	ImGui::End();
}
