package utils

import (
	"fmt"
	"io/fs"
	"log"
	"os"
	"strconv"
	"strings"
)

func Atoi(str string) int {
	num, err := strconv.Atoi(str)
	if err != nil {
		log.Fatal(err)
	}
	return num
}

func GetLines(useRealInput bool) []string {
	var fileName string
	if useRealInput {
		fileName = "input"
	} else {
		fileName = "example"
	}
	file_data, err := fs.ReadFile(os.DirFS(".."), fmt.Sprintf("%s.txt", fileName))
	if err != nil {
		panic(err)
	}
	var lines []string = strings.Split(string(file_data), "\n")
	return lines

}
