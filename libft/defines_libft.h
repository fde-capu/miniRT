/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines_libft.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 11:54:27 by fde-capu          #+#    #+#             */
/*   Updated: 2020/07/13 12:32:50 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_LIBFT_H
# define DEFINES_LIBFT_H

# define TRIM_SET			" \t\n\r\v\f"
# define SPLIT_SET			" \t"
# define COMMENT_SET		"#"
# define DIV				" :: "
# define DOUBLE_PRECISION	10
# define DECIMAL_POINT		"."
# define DEB_STR_ENCLOSURE	"\""
# define ENCLOSE_OPEN		"([{"
# define ENCLOSURES			"()[]{}"

/*
** ft_check related:
*/

# define REG_DOUBLE			"-?\\d+\\.?\\d*"
# define REG_UDOUBLE		"\\d+\\.?\\d*"
# define FUN_DIG			1
# define FUN_PAR			2
# define FUN_SET			3
# define FUN_CHR			4

# define TYPE_SP_NM		"Sphere"
# define TYPE_SP		1
# define TYPE_PL_NM		"Plane"
# define TYPE_PL		2
# define TYPE_SQ_NM		"Square"
# define TYPE_SQ		3
# define TYPE_CY_NM		"Cylinder"
# define TYPE_CY		4
# define TYPE_CAM_NM	"Camera"
# define TYPE_CAM		5
# define TYPE_LHT_NM	"Light"
# define TYPE_LHT		6
# define TYPE_PRM_NM	"Primitive"
# define TYPE_PRM		7
# define TYPE_TRI_NM	"Triangle"
# define TYPE_TRI		8

# define MAT_GEN		1;

#endif
