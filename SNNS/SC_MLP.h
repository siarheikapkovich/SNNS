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
//*** Многослойный персептрон. ***//
class _MWPCLASS MyC_MLP_NeuroNet;
/*{
	// Это полноценный нейроконтроллер с возможностью самоорганизации.
private:
	//__ Структуру адаптировать под стандарт C, для применения в AVR
	// значения помеченные "*" могут не использоваться
	struct MyS_Neuron
	{
		unsigned int      m_NumLauer;    // Номер слоя*
		unsigned int      m_NumInLau;    // Порядковый номер в слое*
		unsigned int      m_DendrCount;  // Количество дендритов
		unsigned int*     m_DendritTo;   // Номер неирона в массиве 
		float**           m_Dendrites;   // Ссылки на аксоны связанных нейронов
		float*            m_Weight;		 // Список весов связей
		float             m_Axon;		 // Выходное значение
		float             m_Quantity;    // Величина спада возбуждения*
		unsigned long     m_QTime;       // Время, по прошествии которого происходит спад*
		bool              m_Active;		 // Признак активации*
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
	float* m_Inputs;                // Входные значения
	float* m_Outputs;               // Выходные значения
	float* m_Targets;               // Вектор для обучения с учителем
	float  m_QError;				// Величина ошибки
	bool m_WorkState;				// Работа/обучение
	UINT m_InputsCount;				// Количество входов
	UINT m_OutputCount;				// Количество выходов
	UINT m_LauerCount;				// Количество слоев
	UINT m_NeuronCount;				// Количество нейронов
	vector<MyS_Neuron*> m_Neurons;	// Список нейронов в сети

	//float GetRandomWeight();
	//void Mutation();
public:
	MyC_MLP_NeuroNet();
	//= Загрузка готовой, обученной НС
	bool LoadConfigFromFile(char *filename);
	//= Установка количества входов, выходов и внутренних слоев
	void Create(MyS_MLP_Creation* param);
	//= Добавить нейрон в слой
	void AddNeuron(UINT lauer, UINT number);
	//= Добавить связь
	void AddSynaps(UINT sourceneuron, UINT receptionneuron, float weight);
	UINT GetInputsCount() {return m_InputsCount;}
	UINT GetOutputsCount(){return m_OutputCount;}
	UINT GetNeuronsCount(){return m_NeuronCount;}
	UINT GetLauerCount()  {return m_LauerCount;}
	//= Установить режим (работа/обучение)
	void SetWorkState(bool state);
	//= Установить вес связи
	void SetWeight(UINT neuron, UINT synaps, float weight);
	//= Установить один вход
	void SetInput(UINT inpnum, float value);
	//= Установить входной вектор
	void SetInput(float* value);

	UINT  Simulate(); // Возвращает номер активированного выходного нейрона
	void Simulate(UINT* result);
	~MyC_MLP_NeuroNet();
};*/