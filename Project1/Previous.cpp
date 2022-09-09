#include <iostream>
#include "Previous.h"
#include "globals.h"

Previous::Previous(int nRows, int nCols)
{
	m_rows = nRows;
	m_cols = nCols;

	//dynamically allocates memory for crumbs in a 2d array of ints filled with 0s
	crumb = new int* [nRows];

	for (int i = 0; i < nRows; i++)
	{
		crumb[i] = new int [nCols];

		for (int j = 0; j < nCols; j++)
		{
			crumb[i][j] = 0;
		}
	}
}

Previous::~Previous()
{
	for (int i = 0; i < m_rows; i++)
	{
		delete[] crumb[i];
	}
	delete[] crumb;
}

bool Previous::dropACrumb(int r, int c)
{
	//to leave a count at a grid point for how many times player is at the point, to use in show prevoius moves
	if (r < 1 || r > m_rows || c < 1 || c > m_cols)
	{
		return false;
	}
	else
	{
		crumb[r-1][c-1]++;
		return true;
	}
}

void Previous::showPreviousMoves() const
{
	clearScreen();

	char p_grid[MAXROWS][MAXCOLS];
	int r, c;

	//creates previous moves grid
	for (r = 0; r < m_rows; r++)
	{
		for (c = 0; c < m_cols; c++)
		{
			if (crumb[r][c] < 1)
			{
				p_grid[r][c] = '.';
			}
			else if (crumb[r][c] > 26)
			{
				p_grid[r][c] = 'Z';
			}
			else
			{
				p_grid[r][c] = 'A' + crumb[r][c] - 1;//increments letters by number of crumbs
			}
		}
	}

	//prints grid
	for (r = 0; r < m_rows; r++)
	{
		for (c = 0; c < m_cols; c++)
			std::cout << p_grid[r][c];
		std::cout << std::endl;
	}
	std::cout << std::endl;

}
