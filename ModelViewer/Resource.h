#pragma once

#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>

typedef unsigned int UINT;

class Resource
{
	friend class ResourceManager;

public:
	Resource(void* pData, const std::string& Filepath) : m_pData(pData), m_Filepath(Filepath) { AddRef(); }

	UINT AddRef() { return ++m_RefCount; }
	UINT RemoveRef();

	void* GetDataPtr() const { return m_pData; }

private:
	UINT m_RefCount = 0;
	void* m_pData = nullptr;

	const std::string m_Filepath;
};

#endif
