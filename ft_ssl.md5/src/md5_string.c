/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 13:51:10 by egoodale          #+#    #+#             */
/*   Updated: 2018/07/12 16:15:08 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"


void	md5_init_ctx(t_md5_ctx *ctx)
{
	ctx->i[0] = 0;
	ctx->i[1] = 0;
 	ctx->state[0] = 0x67452301; // 1100111010001010010001100000001
 	ctx->state[1] = 0xefcdab89; // 11101111110011011010101110001001
 	ctx->state[2] = 0x98badcfe; // 10011000101110101101110011111110
	ctx->state[3] = 0x10325476; // 10000001100100101010001110110
	return ;
}

void md5_print(unsigned char digest[16])
{
	VAR(unsigned, i, -1);
	while (++i < 16)
		ft_printf("%02x", digest[i]);
}

void md5_string(char *s)
{
	t_md5_ctx ctx;
	unsigned char digest[16];
	unsigned len;

	len = ft_strlen(s);
	md5_init_ctx(&ctx);
	md5_update(&ctx, (unsigned char *)s, len);
	md5_final(digest, &ctx);
	ft_printf("MD5 (\"%s\") = ", s);
	md5_print(digest);
	ft_printf("\n");
}