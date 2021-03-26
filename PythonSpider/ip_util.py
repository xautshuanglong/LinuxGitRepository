#!/usr/bin/python3
# -*- coding: UTF-8 -*-

import requests


class IpUtil:
    # https://developer.amap.com/api/webservice/guide/api/ipconfig
    def gaode(ip_address: str):
        headers = {
            'accept': 'application/json, text/javascript, */*; q=0.01',
            'content-type': 'application/x-www-form-urlencoded; charset=UTF-8',
            'ec-ch-ua': '"Google Chrome";v="89", "Chromium";v="89", ";Not A Brand";v="99"',
            'sec-ch-ua-mobile': '?0',
            'sec-fetch-dest': 'empty',
            'sec-fetch-mode': 'cors',
            'sec-fetch-site': 'same-origin',
            'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/89.0.4389.90 Safari/537.36',
            'x-requested-with': 'XMLHttpRequest'
        }
        params = {
            'ip': ip_address,
            'key': 'fcb49ef9f062129a4a0aea6d3bec987f',
            'output': 'json'
        }
        response = requests.get('https://restapi.amap.com/v3/ip', params=params, headers=headers)
        result = response.json()

        # print(response)
        # print(response.url)
        # print(response.encoding)
        # print(response.content)
        # print(response.json())

        return result;

    # https://ip.taobao.com/ipSearch
    # 响应数据 code 值含义，0：成功  1：服务器异常  2：请求参数异常  3：服务器繁忙  4：个人qps超出。
    def taobao(ip_address: str):
        headers = {
            'accept': 'application/json, text/javascript, */*',
            'accept-language': 'zh-CN,zh;q=0.9,en;q=0.8',
            'content-type': 'application/x-www-form-urlencoded',
            'ec-ch-ua': '"Google Chrome";v="89", "Chromium";v="89", ";Not A Brand";v="99"',
            'sec-ch-ua-mobile': '?0',
            'sec-fetch-dest': 'empty',
            'sec-fetch-mode': 'cors',
            'sec-fetch-site': 'same-origin',
            'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/89.0.4389.90 Safari/537.36',
            'x-requested-with': 'XMLHttpRequest'
        }
        params = { 'ip': ip_address }
        response = requests.get("https://ip.taobao.com/outGetIpInfo", params=params, headers=headers)
        result = response.json()
        return result

def main():
    ip_address = '113.108.102.210'
    ip_gaode = IpUtil.gaode(ip_address)
    print("ip info (taobao):")
    print("    status    : %s" % (ip_gaode.get("status")))
    print("    info      : %s" % (ip_gaode.get("info")))
    print("    infocode  : %s" % (ip_gaode.get("infocode")))
    print("    province  : %s" % (ip_gaode.get("province")))
    print("    city      : %s" % (ip_gaode.get("city")))
    print("    adcode    : %s" % (ip_gaode.get("adcode")))
    print("    rectangle : %s" % (ip_gaode.get("rectangle")))
    ip_taobao = IpUtil.taobao(ip_address)
    print("ip info (gaode):")
    print("    msg        : %s" % (ip_taobao.get("msg")))
    print("    code       : %s" % (ip_taobao.get("code")))
    ip_taobao_data = ip_taobao.get('data', None)
    if ip_taobao_data is not None:
        print("    area       : %s" % (ip_taobao_data.get("area")))
        print("    country    : %s" % (ip_taobao_data.get("country")))
        print("    isp_id     : %s" % (ip_taobao_data.get("isp_id")))
        print("    queryIp    : %s" % (ip_taobao_data.get("queryIp")))
        print("    city       : %s" % (ip_taobao_data.get("city")))
        print("    ip         : %s" % (ip_taobao_data.get("ip")))
        print("    isp        : %s" % (ip_taobao_data.get("isp")))
        print("    county     : %s" % (ip_taobao_data.get("county")))
        print("    region_id  : %s" % (ip_taobao_data.get("region_id")))
        print("    area_id    : %s" % (ip_taobao_data.get("area_id")))
        print("    country_id : %s" % (ip_taobao_data.get("country_id")))
        print("    city_id    : %s" % (ip_taobao_data.get("city_id")))



if __name__ == "__main__":
    main()

