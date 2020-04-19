
// Функции графического интерфейса
// Подготовка контекста
void PrepContext();
// Прорисовка сетки и.т.д
void DrawBackGround();
// Прорисовка выделения не5йрона
void DrawSelNeuRect(POINT);
// Прорисовка выделения входа или выхода
void DrawSelInORect(POINT);

void DrawInput(POINT, MyE_NState);
void DrawNeuron(POINT, MyE_NState);
void DrawOutput(POINT, MyE_NState);
