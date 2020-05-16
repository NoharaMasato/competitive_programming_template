package main

import (
	"fmt"
	"github.com/PuerkitoBio/goquery"
	"os"
	"strconv"
)

func fetch_testcase(url string, problem string) {
	doc, err := goquery.NewDocument(url)
	if err != nil {
		fmt.Print("url scarapping failed")
	}
	test_size := doc.Find("pre").Length()
	doc.Find("pre").Each(func(cnt int, s *goquery.Selection) {
		if cnt >= 1 && cnt < test_size/2 {
			if cnt % 2 == 1 {
				file, _ := os.Create(problem + "/inputs/" + strconv.Itoa(cnt/2) + ".txt")
				file.Write(([]byte)(s.Text()))
			} else {
				file, _ := os.Create(problem + "/outputs/" + strconv.Itoa((cnt-1)/2) + ".txt")
				file.Write(([]byte)(s.Text()))
			}
		}
	})
}

func main() {
  word := os.Args[1]
  url := "https://atcoder.jp/contests/abc167/tasks/abc167_" + word
  fetch_testcase(url,word)
}

