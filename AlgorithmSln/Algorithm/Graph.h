#pragma once

struct Vertex
{
	int32 v;
};

// Graph Sample
// 
//     ¡è ¡æ 2
// 0 ¡ê 1  
//     ¡é ¡æ 3 ¡æ 4 ¡ç 5

void CreateSimpleGraph();
void CreateGraphAdjacentList();
void CreateGraphAdjacentMatrix();
void CreateWeightGraphAdjacentMatrix();