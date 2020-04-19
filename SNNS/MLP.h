#include <vector>
#include <list>
using namespace std;

// Распространение сигнала: источник -> приемник
class MyC_Neuron
{
private:
	//unsigned int m_Number;
	unsigned int m_LCount; // 
	DWORD m_Time; // Время спада сигнала
	MyC_Neuron** m_Lincs; // Нейроны которым нужно передать значение
	float* m_Weight; // Веса связей, по которым передать
	float* m_Signal; // Полученные значения взвешенных сигналов от других нейронов
	float   m_Axon;  // Вычисленное значение состояния
public:
	bool SetWeight(unsigned int, float);
	bool SetLinc(MyC_Neuron*);
	bool SetLincs(unsigned int);
	bool AddLinc(MyC_Neuron*);
	bool SetSignal(void); // Если уже вычисленные значения, проще просто суммировать
	bool Simulate(void);		// Основная функция, вычисляет выходное значение нейрона
	float GetAxon();
	MyC_Neuron();
	~MyC_Neuron();
};

class MyC_NeuroNet
{
private:
	unsigned int m_InputCount;
	unsigned int m_OutputCount;
public:
	MyC_NeuroNet();
	~MyC_NeuroNet();
};