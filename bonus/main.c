/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuzuki <yusuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 20:20:50 by yusuzuki          #+#    #+#             */
/*   Updated: 2025/10/29 20:57:28 by yusuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>      // open()
#include <stdio.h>      // printf()
#include "get_next_line_bonus.h"

int main(void)
{
	int fd1 = open("test1.txt", O_RDONLY);
	int fd2 = open("test2.txt", O_RDONLY);
	int fd3 = open("test3.txt", O_RDONLY);
	char *line;

	if (fd1 < 0 || fd2 < 0 || fd3 < 0)
	{
		perror("ファイルオープン失敗");
		return (1);
	}

	printf("=== 同時に3ファイル読み込みテスト ===\n\n");

	line = get_next_line(fd1);
	printf("[fd1] %s", line); free(line);

	line = get_next_line(fd2);
	printf("[fd2] %s", line); free(line);

	line = get_next_line(fd3);
	printf("[fd3] %s", line); free(line);

	line = get_next_line(fd1);
	printf("[fd1] %s", line); free(line);

	line = get_next_line(fd2);
	printf("[fd2] %s", line); free(line);

	line = get_next_line(fd3);
	printf("[fd3] %s", line); free(line);

	close(fd1);
	close(fd2);
	close(fd3);

	return (0);
}

//#include <fcntl.h>
//#include <stdio.h>
//#include "get_next_line_bonus.h"

//int main(void)
//{
//	int fd1 = open("file1.txt", O_RDONLY);
//	int fd2 = open("file2.txt", O_RDONLY);
//	int fd3 = open("file3.txt", O_RDONLY);

//	char *line1;
//	char *line2;
//	char *line3;

//	printf("=== 同時読みテスト開始 ===\n");
//	line1 = get_next_line(fd1);
//	line2 = get_next_line(fd2);
//	line3 = get_next_line(fd3);
//	printf("file1: %s", line1);
//	printf("file2: %s", line2);
//	printf("file3: %s", line3);
//	free(line1);
//	free(line2);
//	free(line3);

//	printf("--- もう一巡 ---\n");
//	line1 = get_next_line(fd1);
//	line2 = get_next_line(fd2);
//	line3 = get_next_line(fd3);
//	printf("file1: %s", line1);
//	printf("file2: %s", line2);
//	printf("file3: %s", line3);
//	free(line1);
//	free(line2);
//	free(line3);

//	close(fd1);
//	close(fd2);
//	close(fd3);
//	return (0);
//}
