from html.parser import HTMLParser
import re

check =''
class MyHTMLParser(HTMLParser):
    # global check
    def __init__(self):
        HTMLParser.__init__(self)
        self.url = ''
        self.links = []
        self.score = 0
    def handle_starttag(self, tag, attrs):
        if(tag == 'a'):
            self.links.append(attrs[0][1])
        if(tag == 'meta'):
            for attr in attrs:
                if(attr[0] == 'content'):
                    self.url = attr[1]

    def handle_data(self, data):
        words = re.split('[^a-zA-Z]', data.lower())
        for word in words:
            if(word == check):
                self.score += 1

def solution(word, pages):
    global check
    check = word.lower()
    url_dict = {}
    other_links = []
    basic_score = []
    total_score = []
    for idx, page in enumerate(pages):
        parser = MyHTMLParser()
        parser.feed(page)
        url_dict[parser.url] = idx
        basic_score.append(parser.score)
        total_score.append(parser.score)
        other_links.append(parser.links)
        # print("url", parser.url)
        # print('other_links', parser.links)
        # print("score", parser.score)

    for i in range(len(basic_score)):
        link_score = 0 if len(other_links[i]) == 0 else basic_score[i] / len(other_links[i])
        for other in other_links[i]:
            if(other not in url_dict): continue
            oIdx = url_dict[other]
            total_score[oIdx] += link_score
    s, ans = 0, 0
    for i, v in enumerate(total_score):
        if(v > s):
            s = v
            ans = i
    return ans