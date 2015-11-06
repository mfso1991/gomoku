/**************************************************************/
// Heuristic

#include "heuristics.h"

std::string row_as_string(const TBoard& board, int row)
{
        std::string out("");

        for (int j = 0; j < 10; j++)
            out += board[row][j];

        return out;
}

std::string column_as_string(const TBoard& board, int column)
{
        std::string out("");

        for (int i = 0; i < 10; i++)
            out += board[i][column];

        return out;
}

std::string diag_nw_se_as_string(const TBoard& board, int diag)
{
        std::string out("");

        for (int j = 0; j < 10; j++)
            if ((diag + j - 9 < 10) && (diag + j - 9 >= 0))
                out += board[j][j + diag - 9];

        return out;
}

std::string diag_ne_sw_as_string(const TBoard& board, int diag)
{
        std::string out("");

        for (int j = 0; j < 10; j++)
            if ((diag - j < 10) && (diag - j >= 0))
                out += board[j][diag - j];

        return out;
}

int evalstring(const std::string& line, char mark)
{

                const char* win;
				
                const char* con_4;
				const char* mid_4;
				const char* t_4_1;
				const char* t_4_2;	
				const char* b_4_l;
				const char* b_4_r;					
                
				const char* threat1;
				const char* threat2;
				const char* threat3;				
				const char* b_3_0_l;
				const char* b_3_0_r;
				
				const char* semiCon_2;
				const char* s_2_2;
				const char* con2_2_l;
				const char* con2_2_r;		
				const char* b_2_2_0_l;
				const char* b_2_2_0_r;

				const char* init1;			
				const char* b_1_2_l;
				const char* b_1_2_r;
				const char* b_1_1_l;
				const char* b_1_1_r;
				const char* b_1_0_l;
				const char* b_1_0_r;

		
        if (mark == 'X')
        {
                win = "XXXXX";
				
                con_4 = "_XXXX_";
				mid_4 = "XX_XX";
				t_4_1 = "X_XXX";
				t_4_2 = "XXX_X";				
				b_4_l = "OXXXX_";
				b_4_r = "_XXXXO";					
                
                threat1 = "_XXX_";
                threat2 = "_XX_X_";
                threat3 = "_X_XX_";				
				b_3_0_l = "OXXX__";
				b_3_0_r = "__XXXO";
				
				semiCon_2 = "_X_X_";
				s_2_2 = "_X__X_";
				con2_2_l = "__XX_";
				con2_2_r = "_XX__";		
				b_2_2_0_l = "___XXO";
				b_2_2_0_r = "OXX___";

				init1 = "___X___";			
				b_1_2_l = "O__X__";
				b_1_2_r = "__X__O";
				b_1_1_l = "O_X___";
				b_1_1_r = "___X_O";
				b_1_0_l = "OX____";
				b_1_0_r = "____XO";
        }
        else
        {
                win = "OOOOO";
				
                con_4 = "_OOOO_";
				mid_4 = "OO_OO";
				t_4_1 = "O_OOO";
				t_4_2 = "OOO_O";
				b_4_l = "XOOOO_";
				b_4_r = "_OOOOX";					
                		
                threat1 = "_OOO_";
                threat2 = "_OO_O_";
                threat3 = "_O_OO_";				
				b_3_0_l = "XOOO__";
				b_3_0_r = "__OOOX";
				
				semiCon_2 = "_O_O_";
				s_2_2 = "_O__O_";
				con2_2_l = "__OO_";
				con2_2_r = "_OO__";		
				b_2_2_0_l = "___OOX";
				b_2_2_0_r = "XOO___";

				init1 = "___O___";			
				b_1_2_l = "X__O__";
				b_1_2_r = "__O__X";
				b_1_1_l = "X_O___";
				b_1_1_r = "___O_X";
				b_1_0_l = "XO____";
				b_1_0_r = "____OX";		
        }
	
        int score = 0;


        if ((line.find(win) != std::string::npos) || (line.find(con_4) != std::string::npos) || (line.find(mid_4) != std::string::npos))
        {
                score += 1200;
        }
        else if ((line.find(b_4_l) != std::string::npos) || (line.find(b_4_l) != std::string::npos) || (line.find(t_4_1) != std::string::npos) || (line.find(t_4_2) != std::string::npos))
        {
                score += 900;
        }				
		
		
		
        else if (line.find(threat1) != std::string::npos)
        {
                score += 1000;
        }      
		else if (line.find(threat2) != std::string::npos)
        {
                score += 500;
        }
        else if (line.find(threat3) != std::string::npos)
        {
                score += 500;
        }		
        else if ((line.find(b_3_0_l) != std::string::npos) || (line.find(b_3_0_r) != std::string::npos))
        {
                score += 10;
        }			
		
		
		else if((line.find(semiCon_2) != std::string::npos) || (line.find(con2_2_l) != std::string::npos) || (line.find(con2_2_r) != std::string::npos))
		{
				score += 8;
		}
		else if((line.find(b_2_2_0_l) != std::string::npos) || (line.find(b_2_2_0_l) != std::string::npos) || (line.find(s_2_2) != std::string::npos))
		{
				score += 6;
		}		
		
		
		
		else if(line.find(init1) != std::string::npos)
		{
				score += 5;
		}		
		else if((line.find(b_1_2_l) != std::string::npos) || (line.find(b_1_2_l) != std::string::npos))
		{
				score += 2;
		}		
		else if((line.find(b_1_1_l) != std::string::npos) || (line.find(b_1_1_l) != std::string::npos))
		{
				score += 1;
		}		
		else if((line.find(b_1_0_l) != std::string::npos) || (line.find(b_1_0_l) != std::string::npos))
		{
				score += 0;
		}					
		
		
		
        return score;

}

int eval(const TBoard& board, char mark)
{
        int score = 0;

        // look for good structures horizontally
        for (int i = 0; i < 10; i++)
        {
            score += evalstring(row_as_string(board, i), mark);
        }

        // look for good structures vertically
        for (int j = 0; j < 10; j++)
        {
            score += evalstring(column_as_string(board, j), mark);
        }

        // look for good structures diagonally
        for (int k = 0; k < 19; k++)
        {
            score += evalstring(diag_nw_se_as_string(board, k), mark);
        }

         // look for good structures diagonally
        for (int k = 0; k < 19; k++)
        {
            score += evalstring(diag_ne_sw_as_string(board, k), mark);
        }

        return score;
}

int eval(const TBoard& board)
{
        return eval(board, 'X') - eval(board, 'O');
}

