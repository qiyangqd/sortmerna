/**
 * @file traverse_bursttrie.hpp
 * @brief header file for traverse_bursttrie.cpp
 * @parblock
 * SortMeRNA - next-generation reads filter for metatranscriptomic or total RNA
 * @copyright 2013-16 Bonsai Bioinformatics Research Group
 * 2014-16 Knight Lab, Department of Pediatrics, UCSD, La Jolla
 *
 * SortMeRNA is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * SortMeRNA is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with SortMeRNA. If not, see <http://www.gnu.org/licenses/>.
 * @endparblock
 *
 * @authors jenya.kopylov@gmail.com
 *          laurent.noe@lifl.fr
 *          helene.touzet@lifl.fr
 *          robknight@ucsd.edu
 */

#ifndef TRAVERSE_BURSTTRIE_H
#define TRAVERSE_BURSTTRIE_H

#include "bitvector.hpp"

using namespace std;

// Universal Levenshtein table for k=1
extern uint32_t table[4][16][14];

/* for each 18-mer hit on the read, we store the 
   key to find the positions and the window number
   on the read at which the 18-mer occurs */
struct id_win
{
  // key value to find index positions
  uint32_t id;
  // the associated window number on the read 
  uint32_t win;
};

/*! @fn traversetrie_align()
    @brief 
    @detail Exact matching of [p_1] in [s_1] is completed fully
    in the trie nodes, continue parallel traversal of the trie
    beginning at [s_2]:<br/>
                   
	  	seed =    |------ [s_1] ------|------ [s_2] ------|<br/>
	  	pattern = |------ [p_1] ------|------ [p_2] --....--|<br/>
	  	          |------ trie -------|----- tail ----....--|<br/>
 
    @param NodeElement* trie_t, root node 
    @param uint32_t lev_t, initial levenshtein state
    @param unsigned char depth, trie node depth
    @param MYBITSET *win_k1_ptr,
    @param MYBITSET *win_k1_full,
    @param bool &accept_zero_kmer,
    @param vector< id_win > &id_hits,
    @param uint32_t readn,
    @param uint32_t win_num,
    @param uint32_t partialwin
    @return none
*/
void
traversetrie_align ( NodeElement *trie_t,
                     uint32_t lev_t,
                     unsigned char depth,
                     MYBITSET *win_k1_ptr,
                     MYBITSET *win_k1_full,
                     bool &accept_zero_kmer,
                     vector< id_win > &id_hits,
                     uint32_t readn,
                     uint32_t win_num,
                     uint32_t partialwin );
#endif