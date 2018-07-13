/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 17:11:08 by egoodale          #+#    #+#             */
/*   Updated: 2018/07/13 14:55:11 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MD5_H
#define MD5_H

enum flag
{
	QUIET = (1 << 0),
	REVERSE = (1 << 1)
};

typedef struct  s_md5_ctx
{
	uint32_t		i[2];
	uint32_t		state[4];
	unsigned char	in[64];
}				t_md5_ctx;

/*
**	Driver and Handles
*/
int							generate_md5(int ac, char **av);
void						md5_parse_args(int ac, char **av);
void						md5_print(unsigned char digest[16]);
void						md5_init_ctx(t_md5_ctx *context);
void						md5_final(unsigned char digest[16], t_md5_ctx *context);
void						md5_update(t_md5_ctx *context, unsigned char *input, size_t input_len);
void						md5_final(unsigned char digest[16], t_md5_ctx *context);
void						md5_transform(uint32_t state[4], unsigned char block[64]);
void						md5_final(unsigned char digest[16], t_md5_ctx *context);
void						md5_memcpy(unsigned char *output, unsigned char *input, size_t len);
void						md5_memset(unsigned char *output, int c, size_t len);
void						rotate_back(uint32_t *a, uint32_t *b, uint32_t *c, uint32_t *d);
void						md5_file(char *filename, char flags);
/*
** Optional Outputs
*/

void						md5_stdin(void);
void						md5_string(char *s);

/*
** Unsigned Char <==> Uint32_t 
*/

void						md5_encode(unsigned char *output, uint32_t *input, size_t len);
void						md5_decode(uint32_t *output, unsigned char *input, size_t len);
				
#endif




