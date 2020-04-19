#include <vector>
#include <list>
using namespace std;

// ��������������� �������: �������� -> ��������
class MyC_Neuron
{
private:
	//unsigned int m_Number;
	unsigned int m_LCount; // 
	DWORD m_Time; // ����� ����� �������
	MyC_Neuron** m_Lincs; // ������� ������� ����� �������� ��������
	float* m_Weight; // ���� ������, �� ������� ��������
	float* m_Signal; // ���������� �������� ���������� �������� �� ������ ��������
	float   m_Axon;  // ����������� �������� ���������
public:
	bool SetWeight(unsigned int, float);
	bool SetLinc(MyC_Neuron*);
	bool SetLincs(unsigned int);
	bool AddLinc(MyC_Neuron*);
	bool SetSignal(void); // ���� ��� ����������� ��������, ����� ������ �����������
	bool Simulate(void);		// �������� �������, ��������� �������� �������� �������
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