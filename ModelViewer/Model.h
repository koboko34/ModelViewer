#pragma once

#ifndef MODEL_H
#define MODEL_H

#include <string>

#include "Component.h"

class ModelData;

/*
*	This class should be abstracting as much as possible from the actual ModelData stored by the ResourceManager.
*	Once the refactor is working, come back and finish the abstractions.
*/

class Model : public Component
{
public:
	Model(const std::string& ModelPath, const std::string& TexturesPath = "");
	Model(const Model& Other) = delete;
	~Model();

	void Shutdown();

	virtual void RenderControls() override;

	void SendTransformToModel();
	void SetShouldRender(bool bNewShouldRender) { m_bShouldRender = bNewShouldRender; }

	ModelData* GetModelData() const { return m_pModelData; }
	bool GetShouldRender() const { return m_bShouldRender; }

private:
	ModelData* m_pModelData = nullptr;

	bool m_bShouldRender;

};

#endif
