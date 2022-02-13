# Реализация класса графа

Вам дан базовый интерфейс для представления ориентированного графа

> class IGraph {
> 
> public:
> 
>  virtual ~IGraph() {};
>  
>  IGraph() {};
>  
>  IGraph(IGraph *_oth) {};
>  
>  virtual void AddEdge(int from, int to) = 0; 
>  
>  virtual int VerticesCount() const = 0; 
>
>  virtual void GetNextVertices(int vertex, std::vector<int> &vertices) const = 0; 
>
>  virtual void GetPrevVertices(int vertex, std::vector<int> &vertices) const = 0; 
>
>  };


Необходимо написать две реализаций интерфейса:

ListGraph, хранящий граф в виде массива списков смежности,
MatrixGraph, хранящий граф в виде матрицы смежности,
  
Также необходимо реализовать конструктор, принимающий IGraph*. 
Такой конструктор должен скопировать переданный граф в создаваемый объект.
Реализуйте в том числе все конструкторы копий и операторы присваивания, если необходимо.
