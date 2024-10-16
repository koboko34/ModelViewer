#pragma once

#ifndef APPLICATION_H
#define APPLICATION_H

#include <chrono>
#include <vector>

#include "Graphics.h"
#include "Shader.h"
#include "Model.h"
#include "Camera.h"
#include "Light.h"

const bool FULL_SCREEN = false;
const bool VSYNC_ENABLED = true;
const float SCREEN_DEPTH = 1000.f;
const float SCREEN_NEAR = 0.3f;

class Application
{
public:
	Application();
	Application(const Application& Other);
	~Application();

	bool Initialise(int ScreenWidth, int ScreenHeight, HWND hWnd);
	void Shutdown();
	bool Frame();

private:
	bool LoadModel(const char* ModelFilename);
	bool Render(double DeltaTime);
	bool RenderPhysicalLight();
	bool RenderPlane();
	void RenderImGui();

private:
	Graphics* m_Graphics;
	Shader* m_Shader;
	Camera* m_Camera;
	Light* m_Light;

	Model* m_SceneLight;
	Model* m_Plane;
	Model* m_Model;

	HWND m_hWnd;

	DirectX::XMFLOAT3 m_ModelPos;
	DirectX::XMFLOAT3 m_ModelRot;
	DirectX::XMFLOAT3 m_ModelScale;

	const char* m_ModelLoadSuccessMessage = "";
	bool m_ShouldRenderLight = true;
	bool m_ShouldRenderPlane = true;

	std::chrono::steady_clock::time_point m_LastUpdate;
	double m_AppTime;
};

#endif
