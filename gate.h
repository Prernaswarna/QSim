/*
This header file provides functionality of quantum Gates respresented as type Matrices. 

The following functions are supported: 
    - getNumQubits : returns type int of number of qubits 
    - printGate() : prints the current gate configuration
*/ 

#ifndef _GATE_H_
#define _GATE_H_

#include "matrix.h" 

class Gate {
    Matrix gate; 
    int num_qubits;
    std::string gate_code;
    friend class Qubits;

    bool checkUnitary(int num_qubits, Matrix gate); 

    public: 
    Gate() = default;
    Gate(int num_qubits);
    Gate(int num_qubits, std::string gate_code);
    Gate(int num_qubits, Matrix gate);
    Gate(int num_qubits, Matrix gate, std::string gate_code);
    Gate(int num_qubits, std::vector<std::vector<Complex>> gate);
    Matrix getMatrix();
    int getNumQubits(); 
    void printGate();
    std::string getGateCode();
};

Gate H();
Gate X();
Gate Y();
Gate Z();
Gate CX();
Gate U(double theta,double phi,double lambda);
Gate Controlled(Gate gate);
#endif
