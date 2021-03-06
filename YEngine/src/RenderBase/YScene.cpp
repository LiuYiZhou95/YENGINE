#include "YScene.h"
#include "YRenderer.h"
#include "YCamera.h"
YScene::YScene()
	:m_defaultCamera(YCamera::Create())
{

}

YScene::~YScene()
{

}

YScene* YScene::create()
{
	YScene * ret = new (std::nothrow) YScene();
	if (ret && ret->init())
	{
		//ret->SubRef();
	}
	else
	{
		delete ret;
		ret = nullptr;
	}
	return ret;
}

void YScene::render(YRenderer* renderer, const glm::mat4& eyeTransform, const glm::mat4* eyeProjection /*= nullptr*/)
{
	render(renderer, &eyeTransform, eyeProjection, 1);
}

void YScene::render(YRenderer* renderer, const glm::mat4* eyeTransforms, const glm::mat4* eyeProjections, unsigned int multiViewCount)
{
	if (YCamera::GetVisitingCamera()!=m_defaultCamera)
	{
		YCamera::m_visitingCamera = m_defaultCamera;
	}
	visit(renderer, m_transform, 0);
	renderer->render();
}

