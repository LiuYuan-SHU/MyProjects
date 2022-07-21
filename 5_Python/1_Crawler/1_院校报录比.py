import requests
import logging
from parsel import Selector

logging.basicConfig(level=logging.INFO,
                    format='%(asctime)s - %(levelname)s: %(message)s')

URL_ori = 'http://www.yanxian.org/html/blb/index.html'
URL_pre = 'http://www.yanxian.org/html/blb/index_'
URL_fix = '.html'
MAX_PAGE_NUM = 40


def get_url(i):
    if i == 1:
        return URL_ori
    else:
        return URL_pre + str(i) + URL_fix


def main():
    key = input("输入要查询的院校全称：")
    for i in range(1, MAX_PAGE_NUM + 1):
        url = get_url(i)
        logging.info(f'获取第 {i} 页')
        html = requests.get(url)
        html.encoding = "utf-8"
        selector = Selector(text=html.text)
        items = selector.xpath(f'//a[contains(@title, "{key}")]')
        if items:
            for item in items:
                print(item.get())


if __name__ == '__main__':
    main()
