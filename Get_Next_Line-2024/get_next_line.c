#include "get_next_line.h"

// Function to join two strings and free the first one
char *ft_free(char *buffer, char *buf)
{
	char *temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

// Function to find the next line and delete it from the buffer
char *ft_next(char *buffer)
{
	int i = 0;
	int j;
	char *line;

	// Find the length of the first line
	while (buffer[i] && buffer[i] != '\n')
		i++;

	// If end of line is '\0', return NULL
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}

	// Allocate memory for the line
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;

	// Copy the remaining content after the first line to the line variable
	while (buffer[i])
		line[j++] = buffer[i++];

	free(buffer);
	return (line);
}

// Function to extract the line from the buffer
char *ft_line(char *buffer)
{
	char *line;
	int i = 0;

	// If no line is found, return NULL
	if (!buffer[i])
		return (NULL);

	// Find the end of line character
	while (buffer[i] && buffer[i] != '\n')
		i++;

	// Allocate memory for the line
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;

	// Copy the content until the end of line character
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}

	// If the end of line character is '\n', add it to the line
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';

	return (line);
}

// Function to read the file and append the content to the result
char *read_file(int fd, char *res)
{
	char *buffer;
	int byte_read;

	// Allocate memory for the buffer if res doesn't exist
	if (!res)
		res = ft_calloc(1, 1);

	// Allocate memory for the buffer
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte_read = 1;

	while (byte_read > 0)
	{
		// Read from the file
		byte_read = read(fd, buffer, BUFFER_SIZE);

		if (byte_read == -1)
		{
			free(buffer);
			return (NULL);
		}

		// Add null terminator to the buffer
		buffer[byte_read] = '\0';

		// Join the buffer with the result
		res = ft_free(res, buffer);

		// Break if end of line is found
		if (ft_strchr(buffer, '\n'))
			break;
	}

	free(buffer);
	return (res);
}

// Function to get the next line from the file
char *get_next_line(int fd)
{
	static char *buffer;
	char *line;

	// Error handling
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);

	// Read the file and update the buffer
	buffer = read_file(fd, buffer);

	if (!buffer)
		return (NULL);

	// Extract the line from the buffer
	line = ft_line(buffer);

	// Update the buffer to remove the extracted line
	buffer = ft_next(buffer);

	return (line);
}

int main(void)
{
	int fd;
	char *line;

	// Open the file for reading
	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Failed to open the file\n");
		return 1;
	}

	// Read lines from the file until the end
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s\n", line);
		free(line);
	}

	// Close the file
	close(fd);

	return 0;
}