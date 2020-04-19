#pragma once
#if defined(MWP_DLL)
	#define _MWPCLASS __declspec(dllexport)
#else
	#define _MWPCLASS __declspec(dllimport)
#endif
#include <windows.h>
#include <vector>
using namespace std;
enum MyE_NeuroInfo
{
	NIE_ACTIVE,
	NIE_NUMLAUER,
	NIE_NUMINLAUER,
	NIE_DENDCOUNT,
	NIE_WEIGHT,
	NIE_AXON
};

enum MyE_NState
{
	NS_NULL,
	NS_AKTIV,
	NS_TORMO
};
struct MyS_MLP_Creation
{
	UINT m_InputCount;
	UINT m_OutputCount;
	UINT m_LauerCount;
	UINT m_NeuronCount;
	UINT* m_Lauers;
	MyS_MLP_Creation()
	{
		UINT m_InputCount = 0;
		UINT m_OutputCount = 0;
		UINT m_LauerCount = 0;
		UINT m_NeuronCount = 0;
	}
};
//*** ������������ ����������. ***//
class _MWPCLASS MyC_MLP_NeuroNet;
/*{
	// ��� ����������� ��������������� � ������������ ���������������.
private:
	//__ ��������� ������������ ��� �������� C, ��� ���������� � AVR
	// �������� ���������� "*" ����� �� ��������������
	struct MyS_Neuron
	{
		unsigned int      m_NumLauer;    // ����� ����*
		unsigned int      m_NumInLau;    // ���������� ����� � ����*
		unsigned int      m_DendrCount;  // ���������� ���������
		unsigned int*     m_DendritTo;   // ����� ������� � ������� 
		float**           m_Dendrites;   // ������ �� ������ ��������� ��������
		float*            m_Weight;		 // ������ ����� ������
		float             m_Axon;		 // �������� ��������
		float             m_Quantity;    // �������� ����� �����������*
		unsigned long     m_QTime;       // �����, �� ���������� �������� ���������� ����*
		bool              m_Active;		 // ������� ���������*
		MyS_Neuron()
		{
			m_NumLauer   = 0;
			m_NumInLau   = 0;
			m_Weight     = 0;
			m_DendrCount = 0;
			m_Dendrites  = 0;
			m_Axon       = 0.0f;
			m_Quantity   = 0.0f;
			m_QTime      = 0;
			m_Active     = false;
		}
	};
	float* m_Inputs;                // ������� ��������
	float* m_Outputs;               // �������� ��������
	float* m_Targets;               // ������ ��� �������� � ��������
	float  m_QError;				// �������� ������
	bool m_WorkState;				// ������/��������
	UINT m_InputsCount;				// ���������� ������
	UINT m_OutputCount;				// ���������� �������
	UINT m_LauerCount;				// ���������� �����
	UINT m_NeuronCount;				// ���������� ��������
	vector<MyS_Neuron*> m_Neurons;	// ������ �������� � ����

	//float GetRandomWeight();
	//void Mutation();
public:
	MyC_MLP_NeuroNet();
	//= �������� �������, ��������� ��
	bool LoadConfigFromFile(char *filename);
	//= ��������� ���������� ������, ������� � ���������� �����
	void Create(MyS_MLP_Creation* param);
	//= �������� ������ � ����
	void AddNeuron(UINT lauer, UINT number);
	//= �������� �����
	void AddSynaps(UINT sourceneuron, UINT receptionneuron, float weight);
	UINT GetInputsCount() {return m_InputsCount;}
	UINT GetOutputsCount(){return m_OutputCount;}
	UINT GetNeuronsCount(){return m_NeuronCount;}
	UINT GetLauerCount()  {return m_LauerCount;}
	//= ���������� ����� (������/��������)
	void SetWorkState(bool state);
	//= ���������� ��� �����
	void SetWeight(UINT neuron, UINT synaps, float weight);
	//= ���������� ���� ����
	void SetInput(UINT inpnum, float value);
	//= ���������� ������� ������
	void SetInput(float* value);

	UINT  Simulate(); // ���������� ����� ��������������� ��������� �������
	void Simulate(UINT* result);
	~MyC_MLP_NeuroNet();
};*/