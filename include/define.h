/*
** define.h for minishell2 in /home/soszyn_h/rendu/PSU/PSU_2015_minishell2/include/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Thu May  5 14:09:27 2016 Hugo SOSZYNSKI
** Last update Thu May  5 14:10:17 2016 Hugo SOSZYNSKI
*/

#ifndef			DEFINE_H_
# define		DEFINE_H_

# ifndef		SUCCESS
#  define		SUCCESS		(0)
# endif			/* !SUCCESS */

# ifndef		ERROR
#  define		ERROR		(1)
# endif			/* !ERROR */

# ifndef		T_CMD
#  define		T_CMD		(0)
# endif			/* !T_CMD */

# ifndef		T_SCOL
#  define		T_SCOL		(1)
# endif			/* !T_SCOL */

# ifndef		T_PIPE
#  define		T_PIPE		(2)
# endif			/* !T_PIPE */

# ifndef		T_RREDIR
#  define		T_RREDIR	(3)
# endif			/* !T_RREDIR */

# ifndef		T_REDIRL
#  define		T_REDIRL	(4)
# endif			/* !T_REDIRL */

# ifndef		T_DREDIRL
#  define		T_DREDIRL	(5)
# endif			/* !T_DREDIRL */

# ifndef		T_NULL
#  define		T_NULL		(6)
# endif			/* !T_END */

# ifndef		T_FILE
#  define		T_FILE		(7)
# endif			/* !T_FILE */

# ifndef		T_STRING
#  define		T_STRING	(8)
# endif			/* !T_STRING */

# ifndef		T_ARG
#  define		T_ARG		(9)
# endif			/* !T_STRING */

# ifndef		T_LINE
#  define		T_LINE		(10)
# endif			/* !T_LINE */

# ifndef		T_ERROR
#  define		T_ERROR		(-1)
# endif			/* !T_ERROR */

#endif			/* !DEFINE_H_ */
