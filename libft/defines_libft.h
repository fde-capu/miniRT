/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines_libft.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 11:54:27 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/14 11:19:39 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_LIBFT_H
# define DEFINES_LIBFT_H

# define TRIM_SET				" \t\n\r\v\f"
# define SPLIT_SET				" \t"
# define COMMENT_SET			"#"
# define DIV					" :: "
# define DOUBLE_PRECISION_ATOD	10
# define DOUBLE_PRECISION		5
# define DOUBLE_PRECISION_DTOA	2
# define DECIMAL_POINT			"."
# define DECIMAL_POINT_CHAR		'.'
# define DEB_STR_ENCLOSURE		"\""
# define ENCLOSE_OPEN			"([{"
# define ENCLOSURES				"()[]{}"

/*
** ft_check related:
*/

# define REG_DOUBLE				"-?\\d+\\.?\\d*"
# define REG_UDOUBLE			"\\d+\\.?\\d*"
# define FUN_DIG				1
# define FUN_PAR				2
# define FUN_SET				3
# define FUN_CHR				4

# define TYPE_SP_NM				"Sphere"
# define TYPE_SP				1
# define TYPE_PL_NM				"Plane"
# define TYPE_PL				2
# define TYPE_SQ_NM				"Square"
# define TYPE_SQ				3
# define TYPE_CY_NM				"Cylinder"
# define TYPE_CY				4
# define TYPE_CAM_NM			"Camera"
# define TYPE_CAM				5
# define TYPE_LHT_NM			"Light"
# define TYPE_LHT				6
# define TYPE_PRM_NM			"Primitive"
# define TYPE_PRM				7
# define TYPE_TRI_NM			"Triangle"
# define TYPE_TRI				8

# define DOTPRODERR				"Dot product must be of same length vectors."
# define ERRDOTPROD				1
# define CROSSPRODERR			"Cross product only possible in 3D."
# define ERRCROSSPROD			2
# define MATRIXSUBMATRIXERR		"matrix_sub_matrix() out of bondaries."
# define ERRMATRIXSUBMATRIX		3
# define COFACTORERR			"Cofactor error. Not a square matrix?"
# define ERRCOFACTOR			4
# define NOTINVERTABLEERR		"Non invertable matrix."
# define ERRNOTINVERTABLE		5

# define X						0
# define Y						1
# define Z						2

/*
** Debugs:
*/

# define DEBUG					debug
# define DEBSTR					debug_str
# define DEBSTR2				debug_str2
# define DEBINT					debug_int
# define DEBINT2				debug_int2
# define SUBDEBINT				subdebug_int
# define SUBDEBINT2				subdebug_int2
# define VERBSTR				debug_str
# define VERBINT				debug_int
# define DEBDBL					debug_double
# define DEBDBL2				debug_double2
# define DEBTDBL				debug_t_dbl
# define DEBRGB					debug_rgb
# define DEBVEC					debug_vector
# define VERBOSE				verbose
# define DEB					debug_str_only
# define DEB2					debug_str_str
# define VERB					debug_str_only
# define DEBSTRADD				debug_str_add
# define DEBMAT					debug_matrix
# define DEBMATVEC				debug_matrix_of_vectors

#endif
