#include "global.h"
bool MyC_Neuron::SetLincs(unsigned int s_Count)
{
	m_LCount = s_Count;

	if(m_Lincs != NULL)
	{
		delete []m_Lincs;
		m_Lincs = NULL;
	}

	if(m_Weight != NULL)
	{
		delete []m_Weight;
		m_Weight = NULL;
	}
	
	m_Lincs = new MyC_Neuron*[m_LCount];
	m_Weight = new float[m_LCount];
	return true;
}

bool MyC_Neuron::AddLinc(MyC_Neuron* s_Linc)
{
	MyC_Neuron** s_Temp;
	if(m_Lincs == NULL) return true;
	// Сохраняем текущие значения во временном массиве
	s_Temp = new MyC_Neuron*[m_LCount];
	for(unsigned int i = 0; i < m_LCount; i++)
	{
        s_Temp[i] = m_Lincs[i];
	}
	delete []m_Lincs;
	m_Lincs = new MyC_Neuron*[m_LCount + 1];
	for(unsigned int i = 0; i < m_LCount; i++)
	{
        m_Lincs[i] = s_Temp[i];
	}
	m_Lincs[m_LCount] = s_Linc;
	m_LCount++;
	// Удаляем временный массив
	delete []s_Temp;
	return true;
}

MyC_Neuron::MyC_Neuron()
{
	m_Lincs = NULL;
	m_Weight = NULL;
	m_LCount = 0;
}

MyC_Neuron::~MyC_Neuron()
{
}