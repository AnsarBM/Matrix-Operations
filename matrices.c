# include<stdio.h>
#include <stdlib.h>
#include <string.h>

char A, B, S, P;                                          /*Characters for matrix A, B, Sum and Product*/

int rows, columns;
int i,j,k;

int elements;
int total_elements;
int row_number, column_number;
int choice;

int sum[50][50];
int product[50][50];

int rows_matrix_A;
int columns_matrix_A;
int rows_matrix_B;
int columns_matrix_B;

int A_matrix[50][50];
int B_matrix[50][50];

    

/*Function for taking the number of ROWS and COLUMNS of each Matrix from the user*/
int number_of_rows_and_columns_of_matrix(char matrix_letter);

int number_of_rows_and_columns_of_matrix(char matrix_letter)
{
    if (matrix_letter == 'A')
    {
        printf("\n**For the FIRST matrix**");
        printf("\nWhat is total number of ROWS:    ");
        scanf("%d",&rows_matrix_A);

        printf("What is total number of COLUMNS: ");
        scanf("%d",&columns_matrix_A);

        printf("Your FIRST matrix is %d by %d.\n", rows_matrix_A, columns_matrix_A);

        return rows_matrix_A, columns_matrix_A;
    }

    else if (matrix_letter=='B') 
    {
        printf("\n**For the SECOND matrix**");
        printf("\nWhat is total number of ROWS:    ");
        scanf("%d",&rows_matrix_B);

        printf("What is total number of COLUMNS: ");
        scanf("%d",&columns_matrix_B);

        printf("Your SECOND  matrix is %d by %d.\n", rows_matrix_B, columns_matrix_B);

        return rows_matrix_B, columns_matrix_B;
    }
}


/*Function for taking MATRIX ELEMENTS from the user*/
int take_elements_matrix(char matrix_letter);

int take_elements_matrix(char matrix_letter)
{

    if (matrix_letter=='A')
    {
        elements = 0;
        total_elements = rows_matrix_A*columns_matrix_A;

        printf("\nFIRST matrix Elements row by row.\n\n");

        if (elements <= total_elements)
            {
                for (i=1; i<rows_matrix_A + 1; i++)
                {   
                    for (j=1; j<columns_matrix_A + 1; j++)
                    {
                        row_number = i;
                        column_number = j;
                        printf("Enter the element of Row:[%d] Column:[%d]:  ", row_number, column_number);
                        scanf("%d", &A_matrix[i][j]);
                        elements++;
                    }   
                }
            } 
        return A_matrix[rows_matrix_A][columns_matrix_A];
    }
    
    else if (matrix_letter=='B') 
    {

        elements = 0;
        total_elements = rows_matrix_B*columns_matrix_B;

        printf("\nSECOND matrix Elements row by row.\n\n");

        if (elements <= total_elements)
            {
                for (i=1; i<rows_matrix_B + 1; i++)
                {   
                    for (j=1; j<columns_matrix_B + 1; j++)
                    {
                        row_number = i;
                        column_number = j;
                        printf("Enter the element of Row:[%d] Column:[%d]:  ", row_number, column_number);
                        scanf("%d", &B_matrix[i][j]);
                        elements++;
                    }   
                }
            } 
        return B_matrix[rows_matrix_B][columns_matrix_B];
    }
    
}

/*Function for printing the MATRIX*/
int print_matrix(char matrix_letter);

int print_matrix(char matrix_letter)
{

    if (matrix_letter=='A')
    {
        for (i=1; i<rows_matrix_A + 1; i++)
        {   
            for (j=1; j<columns_matrix_A + 1; j++)
            {
                printf("%d   ", A_matrix[i][j]);     
            }
            printf("\n");
        }
        /*printf("\n");*/
    }
    else if (matrix_letter=='B') 
    {
        for (i=1; i<rows_matrix_B + 1; i++)
        {   
            for (j=1; j<columns_matrix_B + 1; j++)
            {
                printf("%d   ", B_matrix[i][j]);     
            }
            printf("\n");
        }
        /*printf("\n");*/
    }

    else if (matrix_letter=='S') 
    {
        rows = rows_matrix_A;            /*It does not matter you can write A or B, the two matrices have same rows and columns, so does the sum matrix*/
        columns = columns_matrix_A;

        for (i=1; i<rows + 1; i++)
        {   
            for (j=1; j<columns + 1; j++)
            {
                printf("%d   ", sum[i][j]);     
            }
            printf("\n");
        }
        /*printf("\n");*/
    }

    else if (matrix_letter=='P') 
    {
        rows = rows_matrix_A;            /*Becareful with the rows and columns. If you interchange them, multiplication may not be performed.*/
        columns = columns_matrix_B;

        for (i=1; i<rows + 1; i++)
        {   
            for (j=1; j<columns + 1; j++)
            {
                printf("%d   ", product[i][j]);     
            }
            printf("\n");
        }
        /*printf("\n");*/

    }
    return 1;
}

/*Function for ADDING two matrices*/
int sum_of_matrices(int matrix_A[50][50], int matrix_B[50][50]);

int sum_of_matrices(int matrix_A[50][50], int matrix_B[50][50])
{
    
    rows = rows_matrix_A;               /*Since the size of matrix_A and B are the same you can also write rows = rows_matrix_B*/ 
    columns = columns_matrix_A;         /*and columns = columns_matrix_B*/
    sum[rows][columns];
    memset(sum, 0, sizeof(sum));

    for (i=1; i<rows+1; i++)
    {   
        for (j=1; j<columns+1; j++)
        {
            sum[i][j] += A_matrix[i][j] + B_matrix[i][j];     
        }
        printf("\n");
    }
    /*printf("\n");*/
    return sum[rows][columns];
}


/*Function for MULTIPLICATION of two matrices*/
int product_of_matrices(int matrix_A[50][50], int matrix_B[50][50]);

int product_of_matrices(int matrix_A[50][50], int matrix_B[50][50])
{
    
    int terms_to_add;

    rows = rows_matrix_A;               /*Be careful! If you interchange the rows and columns of A and B.*/ 
    columns = columns_matrix_B;         /*Instead of [A*B] you will be calculating [B*A] which may not necessarily be equal*/  
    terms_to_add = columns_matrix_A;               /*This gives number of terms that should be added in each row of the product matrix. It is the same as rows_matrix_B*/

    product[rows][columns];
    memset(product, 0, sizeof(product));

    for (i=1; i<rows+1; i++)
    {   
        for (j=1; j<columns+1; j++)
        {   
            if (i==j)
            {   if (i==1)
                {
                    for (k=0 ; k < terms_to_add; k++ )
                        {
                            product[i][j] += (A_matrix[i][j+k] * B_matrix[j+k][i]);           /*This gives the first term of the product matrix*/
                        }
                          
                }
                else if (i>1)
                {
                    for (k=0; k < terms_to_add; k++ )
                    {
                        product[i][j] += (A_matrix[i][k+1] * B_matrix[k+1][j]);             /*This gives the rest of diagonal terms of the product matrix*/
                    }
                     
                }
            } 

            else
            {
                for (k=0; k < terms_to_add; k++ )
                {
                    product[i][j] += (A_matrix[i][k+1] * B_matrix[k+1][j]);           /*This gives the remaining terms of the product matrix*/
                }    
            }     
        }
        printf("\n");
    }
    /*printf("\n");*/
    return product[rows][columns];
}

/*Below the MAIN function*/
int main()
{
    char A, B, S, P;

    printf("\t\n\n***This program can give you ADDITION and/or MULTIPLICATION of two matrices***\n\n"); 

    /*Take Number of ROWS & COLUMNS and ELEMENTS of the Matrices from the user*/
    number_of_rows_and_columns_of_matrix('A');
    take_elements_matrix('A');
    printf("\nYour First Matrix, A is: \n");
    print_matrix('A');

    number_of_rows_and_columns_of_matrix('B');
    take_elements_matrix('B');
    printf("\nYour Second Matrix, B is: \n");
    print_matrix('B');
    

    while(1)
    {
        printf("\nWhat do you want to do?\n1) Find ADDITION of two Matrices, Enter 1.\n" 
                                          "2) Find MULTIPLICATION of two Matrices, Enter 2.\n" 
                                          "3) Find Both ADDITION and MULTIPLICATION of two Matrices, Enter 3.\n"
                                          "4) Enter new Matrices.\n"
                                          "5) To EXIT, Enter 4.\n\n");
        scanf("\n%d",&choice);
    

        switch (choice)
        {   

            case 1: /*ADDITION*/
                    /*printf("\nYou can ADD two matrices if and only if they have the same dimensions.\n"
                            "That is, their number of rows and columns are the same.\n\n");*/
            

                    /*Check if ADDITION can be done based on the matrices dimensions*/
                    if ((rows_matrix_A != rows_matrix_B) || (columns_matrix_A != columns_matrix_B))
                    {
                        printf("The number of ROWS and COLUMNS of the matrices do not match.\n"
                        "Addition on the matrices cannot be performed.\n"
                        "Please try again!\n\n");
                    }
                    else
                    {

                        printf("\nYour First Matrix, A is: \n");
                        print_matrix('A');

                        printf("\nYour Second Matrix, B is: \n");
                        print_matrix('B');

                        /*Add the two matrices A and B and print its sum*/
                        sum_of_matrices(A_matrix, B_matrix);

                        printf("The sum, S of the two matrices A and B is the matrix: \n");
                        print_matrix('S');
                    }
                    break;
            

            case 2: /*MULTIPLICATION*/
                    /*printf("You can MULTIPLY two matrices if and only if\n" 
                            "the number of COLUMNS of the FIRST Matrix, A is the same as the number of ROWS in the SECOND Matrix, B.\n");*/
                

                    /*Check if MULTIPLICATION can be done based on the matrices dimensions*/
                    if (columns_matrix_A != rows_matrix_B)
                    {
                        printf("The number of COLUMNS of the First Matrix, A and number of ROWS of the SECOND Matrix do not match.\n"
                        "Multiplication of the two matrices cannot be performed.\n"
                        "Please try again!\n\n");
                    }
                    else
                    {
                        printf("\nYour First Matrix, A is: \n");
                        print_matrix('A');

                        printf("\nYour Second Matrix, B is: \n");
                        print_matrix('B');

                        /*Add the two matrices A and B and print its sum*/
                        product_of_matrices(A_matrix, B_matrix);

                        printf("The product,P of the two matrices A and B is the matrix: \n");
                        print_matrix('P');
                    }
                    break;

            case 3: /*BOTH ADDITION AND MULTIPLICATION*/
                    
                    /*ADDITION*/
                    printf("\nYour First Matrix, A is: \n");
                    print_matrix('A');

                    printf("\nYour Second Matrix, B is: \n");
                    print_matrix('B');

                    /*Check if ADDITION can be done based on the matrices dimensions*/
                    if ((rows_matrix_A != rows_matrix_B) || (columns_matrix_A != columns_matrix_B))
                    {
                        printf("The number of ROWS and COLUMNS of the matrices do not match.\n"
                        "Addition on the matrices cannot be performed.\n"
                        "Please try again!\n\n");
                    }
                    else
                    {
                        /*Add the two matrices A and B and print its sum*/
                        sum_of_matrices(A_matrix, B_matrix);

                        printf("The sum, S of the two matrices A and B is the matrix: \n");
                        print_matrix('S');
                    }



                    /*MULTIPLICATION*/

                    /*Check if MULTIPLICATION can be done based on the matrices dimensions*/
                    if (columns_matrix_A != rows_matrix_B)
                    {
                        printf("The number of COLUMNS of the First Matrix, A and number of ROWS of the SECOND Matrix do not match.\n"
                        "Multiplication of the two matrices cannot be performed.\n"
                        "Please try again!\n\n");
                        return 1;
                    }
                    else
                    {
                        /*Add the two matrices A and B and print its sum*/
                        product_of_matrices(A_matrix, B_matrix);

                        printf("The product, P of the two matrices A and B is the matrix: \n");
                        print_matrix('P');
                    }
                    break;     


            case 4: /*ENTER NEW MATRICES*/

                    number_of_rows_and_columns_of_matrix('A');
                    take_elements_matrix('A');
                    printf("\nYour First Matrix, A is: \n");
                    print_matrix('A');

                    number_of_rows_and_columns_of_matrix('B');
                    take_elements_matrix('B');
                    printf("\nYour Second Matrix, B is: \n");
                    print_matrix('B');

                    break;  


            case 5: /*END THE PROGRAM TO EXIT*/
                    printf("\nThe program is exiting...\n");
                    printf("\t***End of Program***\n\n");

                    return 0;
                    

            default: /*USER ENTERED UNAVAILABLE CHOICE*/
                    printf("\nWrong choice. Please try again!\n\n");
                    break;
        } 
        

    }
    return 0;
}