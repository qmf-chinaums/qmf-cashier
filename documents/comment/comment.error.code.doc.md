## 错误码说明
错误码共分为两层，main_code与sub_code。每一接口返回数据中都会含有main_code与sub_code。  
main_code表示主错误码，在main_code确定的情况下，会含有细分后的次级错误码sub_code。  
商户联调只需关心main_code与sub_code。

<table>
    <tr>
        <th rowspan="1">序号</th>
        <th>main_code</th>
        <th>sub_code_platform</th>
        <th>sub_code</th>
        <th>说明</th>
    </tr>
    <tr>
        <th rowspan="1">01</th>
        <td>MC_110001</td>
        <td>-</td>
        <td>-</td>
        <td>表示本次接口调用的结果为业务处理正确完成。即交易状态为成功，<br>但可能存在不影响交易结果其他状态为非成功的情况。<br>详见以下sub_code。</td>
    </tr>
    <tr>
        <th rowspan="1">02</th>
        <td>-</td>
        <td>03</td>
        <td>SC_100100</td>
        <td>交易成功或补发成功。[打印纸质签购单成功，并且签名上送成功。]</td>
    </tr>
    <tr>
        <th rowspan="1">03</th>
        <td>-</td>
        <td>03</td>
        <td>SC_100101</td>
        <td>交易成功或补发成功。[打印纸质签购单成功，但签名上送失败。]</td>
    </tr>
    <tr>
        <th rowspan="1">04</th>
        <td>-</td>
        <td>03</td>
        <td>SC_100102</td>
        <td>交易成功。[打印纸质签购单失败，但签名上送成功。]</td>
    </tr>
    <tr>
        <th rowspan="1">05</th>
        <td>-</td>
        <td>03</td>
        <td>SC_100103</td>
        <td>交易成功。[打印纸质签购单失败，并且签名上送失败。]</td>
    </tr>
    <tr>
        <th rowspan="1">06</th>
        <td>-</td>
        <td>03</td>
        <td>SC_100104</td>
        <td>交易成功或补发成功（免签、非免签）。[电子签购单加载失败（未签名、未打印）。]</td>
    </tr>
    <tr>
        <th rowspan="1">07</th>
        <td>-</td>
        <td>03</td>
        <td>SC_100105</td>
        <td>交易成功或补发成功（免签名）。[打印纸质签购单成功。]</td>
    </tr>
    <tr>
        <th rowspan="1">08</th>
        <td>-</td>
        <td>03</td>
        <td>SC_100106</td>
        <td>交易成功（免签名）。[打印纸质签购单失败。]</td>
    </tr>
    <tr>
        <th rowspan="1">09</th>
        <td>-</td>
        <td>03</td>
        <td>SC_100107</td>
        <td>交易成功或补发成功（免签名）。[电子签购单加载失败（未签名、未打印）。]</td>
    </tr>
    <tr>
        <th rowspan="1">10</th>
        <td>-</td>
        <td>03</td>
        <td>SC_100108</td>
        <td>交易成功或补发成功。[发送短信签购单成功，且签名上送成功。]</td>
    </tr>
    <tr>
        <th rowspan="1">11</th>
        <td>-</td>
        <td>03</td>
        <td>SC_100109</td>
        <td>交易成功或补发成功。[发送短信签购单成功，但签名上送失败。]</td>
    </tr>
    <tr>
        <th rowspan="1">12</th>
        <td>-</td>
        <td>03</td>
        <td>SC_100110</td>
        <td>交易成功。[发送短信签购单失败，但签名上送成功。]</td>
    </tr>
    <tr>
        <th rowspan="1">13</th>
        <td>-</td>
        <td>03</td>
        <td>SC_100111</td>
        <td>交易成功。[发送短信签购单失败，并且签名上送失败。]</td>
    </tr>
    <tr>
        <th rowspan="1">14</th>
        <td>-</td>
        <td>03</td>
        <td>SC_100112</td>
        <td>交易成功或补发成功（免签名）。[发送短信签购单成功]</td>
    </tr>
    <tr>
        <th rowspan="1">15</th>
        <td>-</td>
        <td>03</td>
        <td>SC_100113</td>
        <td>交易成功（免签名）。[发送短信签购单失败]</td>
    </tr>
    <tr>
        <th rowspan="1">16</th>
        <td>-</td>
        <td>03</td>
        <td>SC_100114</td>
        <td>交易成功或补发成功（免签、非免签）。[不发送签购单]</td>
    </tr>
    <tr>
        <th rowspan="1">17</th>
        <td>-</td>
        <td>03</td>
        <td>SC_100199</td>
        <td>交易成功或补发成功。（以上未列举的情况）</td>
    </tr>
    <tr>
        <th rowspan="1">18</th>
        <td>-</td>
        <td>03</td>
        <td>SC_100300</td>
        <td>非交易类接口业务处理成功（非消费、消费撤销、预授权、预授权完成、预授权撤销、预授权完成撤销、联机退货等）</td>
    </tr>
    <tr>
        <th rowspan="1"></th>
        <td>======</td>
        <td>======</td>
        <td>======</td>
        <td>======</td>
    </tr>
    <tr>
        <th rowspan="1">19</th>
        <td>MC_210001</td>
        <td>-</td>
        <td>-</td>
        <td>接口调用失败（网络错误，网络失败）。<br>详见以下sub_code。</td>
    </tr>
    <tr>
        <th rowspan="1">20</th>
        <td>-</td>
        <td>03</td>
        <td>SC_200100</td>
        <td>表示接口由于网络因素业务处理失败（交易失败、补发失败等等）</td>
    </tr>
    <tr>
        <th rowspan="1"></th>
        <td>======</td>
        <td>======</td>
        <td>======</td>
        <td>======</td>
    </tr>
    <tr>
        <th rowspan="1">21</th>
        <td>MC_310001</td>
        <td>-</td>
        <td>-</td>
        <td>表示接口由于各种业务原因处理失败。<br>详见以下sub_code。</td>
    </tr>
    <tr>
        <th rowspan="1">22</th>
        <td>-</td>
        <td>03</td>
        <td>SC_300100</td>
        <td>用户主动取消流程（按了手机back键等） </td>
    </tr>
    <tr>
        <th rowspan="1">23</th>
        <td>-</td>
        <td>03</td>
        <td>SC_300102</td>
        <td>用户主动取消流程（其他原因）</td>
    </tr>
    <tr>
        <th rowspan="1">24</th>
        <td>-</td>
        <td>03</td>
        <td>SC_300103</td>
        <td>获取位置信息失败</td>
    </tr>
    <tr>
        <th rowspan="1">25</th>
        <td>-</td>
        <td>03</td>
        <td>SC_300104</td>
        <td>补发签购单，打印纸质签购单失败</td>
    </tr>
    <tr>
        <th rowspan="1">26</th>
        <td>-</td>
        <td>03</td>
        <td>SC_300105</td>
        <td>补发签购单，发送电子签购单失败</td>
    </tr>
    <tr>
        <th rowspan="1">27</th>
        <td>-</td>
        <td>04</td>
        <td>SC_300401</td>
        <td>刷卡等待超时</td>
    </tr>
    <tr>
        <th rowspan="1">28</th>
        <td>-</td>
        <td>04</td>
        <td>SC_300402</td>
        <td>发生异常，请确认设备</td>
    </tr>
    <tr>
        <th rowspan="1">29</th>
        <td>-</td>
        <td>04</td>
        <td>SC_300403</td>
        <td>卡片拒绝交易，请以当日交易状态为准</td>
    </tr>
    <tr>
        <th rowspan="1">30</th>
        <td>-</td>
        <td>04</td>
        <td>SC_300404</td>
        <td>用户取消交易（按了POS机取消键或等待超时）</td>
    </tr>
    <tr>
        <th rowspan="1">31</th>
        <td>-</td>
        <td>03</td>
        <td>SC_999999</td>
        <td>未列举出来的错误（默认错误码）</td>
    </tr>
    <tr>
        <th rowspan="1">32</th>
        <td>-</td>
        <td>02</td>
        <td>其他(非SC开头)</td>
        <td>交易信息后台校验错误，以具体返回错误提示信息为准</td>
    </tr>
    <tr>
        <th rowspan="1">33</th>
        <td>-</td>
        <td>04</td>
        <td>其他(非SC开头)</td>
        <td>POS固件校验数据时发现异常</td>
    </tr>
    <tr>
        <th rowspan="1"></th>
        <td>======</td>
        <td>======</td>
        <td>======</td>
        <td>======</td>
    </tr>
    <tr>
        <th rowspan="1">34</th>
        <td>MC_310002</td>
        <td>-</td>
        <td>-</td>
        <td>表示接口由于请求参数校验错误处理失败。<br>详见以下sub_code。</td>
    </tr>
    <tr>
        <th rowspan="1">35</th>
        <td>-</td>
        <td>03</td>
        <td>SC_320100</td>
        <td>商户传入的请求参数校验错误</td>
    </tr>
</table>
