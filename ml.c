#include <stdio.h>
void GR_DES(float m_now , float b_now ,float len ,  float L , float array_x[] , float array_y[] , float * m , float * b){
    float m_grad = 0 ;
    float b_grad = 0 ;

    for(int i=0 ; i<len ; i++){
        float x = array_x[i] ;
        float y = array_y[i] ;

        m_grad += -(2.0/len) * x *(y -(m_now * x + b_now)) ;
        b_grad += -(2.0/len) *(y -(m_now * x + b_now)) ;
    }
    *m = m_now - m_grad * L ;
    *b = b_now - b_grad * L ;

    
}


void main(){
    float m = 0, b = 0; 
    float learning_rate = 0.01;
    int len = 5;
    float x_vals[] = {1, 2, 3, 4, 5};
    float y_vals[] = {2, 4, 6, 8, 10}; 

    int epochs = 3000;
    for (int i = 0; i < epochs; i++) {
        GR_DES(m, b, len, learning_rate, x_vals, y_vals, &m, &b);
    }

    printf("Final values: m = %0.10f, b = %0.10f\n", m, b);
   
}