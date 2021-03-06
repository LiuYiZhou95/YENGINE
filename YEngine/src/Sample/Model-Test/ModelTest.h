#ifndef MODELTEST_H_
#define MODELTEST_H_

#include "YNode.h"
#include "YCustomCommand.h"
#include "YType.h"

class YShader;
class GLFWwindow;
class YTexture2D;
class YModel;
class ModelTest :public YNode
{


public:
	ModelTest();
	virtual ~ModelTest();
public:
	Y_CREATESAMPLE(ModelTest);
	virtual void draw(YRenderer* renderer, const glm::mat4& transform, uint32_t flags) override;

	//virtual void onDraw();
protected:
	virtual bool init() override;
	virtual void initBuffers();
	void onDraw(const glm::mat4* transform, uint32_t);


protected:
	YCustomCommand m_customCommand;
	YShader*    m_Modelshader;
	YShader*    m_ModelNormalshader;
	unsigned int m_VBO;
	unsigned int m_VAO;
	unsigned int m_LightVAO;
	bool		 m_bNoramlLine;
	bool         m_bFaceLine;
	bool		 m_bTangentLine;
	bool         m_bBitTangentLine;
	YModel*      m_pModel;
	

};
#endif
