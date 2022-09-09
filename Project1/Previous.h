#ifndef PREVIOUS_H
#define PREVIOUS_H

class Previous
{
public:
    Previous(int nRows, int nCols);
    bool dropACrumb(int r, int c);
    void showPreviousMoves() const;

    //deconstructor
    ~Previous();
private:
    int m_rows;
    int m_cols;
    int** crumb;//2d array with number of crumb at each grid location
};

#endif // !PREVIOUS_H
