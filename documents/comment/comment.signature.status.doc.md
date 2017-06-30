## signatureStatus说明
该字段内容格式：2|0  
- 竖线之前的数字表示补发签购单时名状态  
- 竖线之后的数字表示正常交易时签名状态  

<table>
    <tr>
        <th rowspan="1">序号</th>
        <th>值</th>
        <th>含义</th>
    </tr>
    <tr>
        <th rowspan="1">01</th>
        <td>0</td>
        <td>未签名</td>
    </tr>
    <tr>
        <th rowspan="1">02</th>
        <td>1</td>
        <td>签名中</td>
    </tr>
    <tr>
        <th rowspan="1">03</th>
        <td>2</td>
        <td>签名成功</td>
    </tr>
    <tr>
        <th rowspan="1">04</th>
        <td>3</td>
        <td>签名失败</td>
    </tr>
</table> 

- 那么，signatureStatus为 2|0 表示正常交易流程中未签名，补发时签名成功了。

