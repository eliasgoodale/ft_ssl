/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 15:30:58 by egoodale          #+#    #+#             */
/*   Updated: 2018/07/13 22:00:40 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef SHA256_H
#	define SHA256_H

#define MSG_BLK_SZ 64

typedef struct		s_sha256_ctx
{
	uint32_t		state[8];
	uint32_t		len_low;
	uint32_t		len_high;
	int_least16_t	message_block_index;
	uint8_t			message_block[64];
	int				computed;
	int				corrupted;
}					t_sha256_ctx;

enum {
	SUCCESS = 0, _NULL,
	EINPUTOOLONG,
	ESTATE,
	EBADPARAM
};

/*
** Argument Parsing
*/

void				sha256_parse_flags(char *flag_s);
int					sha256_parse_string_args(int ac, char **av, int arg);
void				sha256_parse_args(int ac, char **av);
int					generate_sha256(int ac, char **av);
int					sha256_parse_file_args(int ac, char **av, int arg);

/*
** Helper
*/

int					sha256_add_length(t_sha256_ctx *ctx, unsigned len);
void				sha256_pad_message(t_sha256_ctx *ctx, uint8_t pad_bits);
void				generate_final_params(uint8_t masks[8], uint8_t marks[8]);
void				sha256_print(uint8_t digest[32], char *input);
void				sha256_print_digest(uint8_t digest[32]);

/*
** Hash
*/

void				modulate_fifth(uint32_t o[8], uint32_t tone1,
					uint32_t tone2);
void				sha256_hash(uint32_t w[64], uint32_t m[8]);
void				sha256_encode(uint32_t output[64], uint8_t input[64],
					unsigned len);
void				sha256_process_message(t_sha256_ctx *ctx);

/*
** Digest
*/

int					sha256_result(t_sha256_ctx *ctx, uint8_t digest[32]);
void				sha256_finalize(t_sha256_ctx *ctx, uint8_t pad_bits);
int					sha256_input(t_sha256_ctx *ctx, uint8_t *input,
					uint_least64_t len);

/*
** String
*/

void				sha256_init_ctx(t_sha256_ctx *ctx);
void				sha256_string(char *input);

/*
** File
*/

void				sha256_file(char *filename);

/*
** Stdin
*/

void				sha256_stdin(void);

#	endif
