let dataIndex = 4 // 数据索引 ['中文国家名', '英文国家名', '年', 'GDP单位$', 'GDP单位万亿$', '人口', '人均GDP']
let textColor = '#fff'

// 初始数据，假数据。比1960年的数据稍小一点即可（如果一样的话，开始时没有动态效果）
const defaultData = [
  ['美国', 'America', 1960, 54329999360, 5400, 18067100, 300],
  ['英国', 'Britain', 1960, 7323396505, 700.34, 5240000, 139],
  ['法国', 'French', 1960, 6222547763, 600.25, 4662170, 133],
  ['中国', 'China', 1960, 5971646873, 500.16, 66707000, 8],
  ['日本', 'Japan', 1960, 4430734131, 400.07, 9321600, 47],
  ['加拿大', 'Canada', 1960, 4046172160, 400.62, 1790900, 225],
  ['意大利', 'Italy', 1960, 4038529024, 400.85, 5019970, 80],
  ['印度', 'India', 1960, 3702988390, 300.3, 45054800, 8],
  ['澳大利亚', 'Australia', 1960, 1857766809, 100.78, 1027650, 181],
  ['瑞典', 'Sweden', 1960, 1582258483, 100.23, 748466, 211],
  ['巴西', 'Brazil', 1960, 1516557004, 100.66, 7217920, 21],
  ['土耳其', 'Turkey', 1960, 1399506739, 100.95, 2747230, 50],
  ['墨西哥', 'Mexico', 1960, 1304000000, 100.4, 3777190, 34],
  ['荷兰', 'Netherlands', 1960, 1227673395, 100.77, 1148660, 106],
  ['西班牙', 'Spain', 1960, 1207212646, 100.72, 3045500, 39]
]
const myChart = echarts.init(document.getElementById('main'))
let option = {
  title: {
    text: '近60年各国GDP（Top10）',
    textStyle: {
      color: textColor,
      fontSize: 40,
      fontFamily: '微软雅黑' // '华文彩云'
    },
    left: 'center',
    top: 30
  },
  grid: {
    top: 80,
    right: 180
  },
  xAxis: {
    show: false,
    max: 'dataMax'
  },
  yAxis: {
    axisLine: {
      show: false
    },
    axisTick: {
      show: false
    },
    axisLabel: {
      color: textColor
    },
    type: 'category',
    inverse: true, // 是否反向坐标轴
    animationDuration: 300,
    animationDurationUpdate: 300,
    max: 9 // only the largest 3 bars will be displayed
  },
  series: [
    {
      realtimeSort: true,
      name: 'GDP',
      type: 'bar',
      data: defaultData,
      barWidth: 32,
      // （x轴和y轴分别展示什么数据）
      encode: {
        x: dataIndex,
        y: 0
      },
      label: {
        show: true,
        position: 'right',
        valueAnimation: true,
        textBorderWidth: 0,
        color: textColor,
        formatter: function (param) {
          // console.log(param)
          return `{${param.value[1]}|} ` + param.value[dataIndex]
        },
        rich: rich
      },
      itemStyle: {
        color: function (params) {
          return colors[params.value[0]]
        }
      }
    }
  ],
  animationDuration: 0,
  animationDurationUpdate: 1000,
  animationEasing: 'linear',
  animationEasingUpdate: 'linear',
  graphic: {
    elements: [
      {
        type: 'text',
        right: 190,
        bottom: 100,
        style: {
          text: 1960,
          font: 'bolder 80px monospace',
          fill: textColor
        },
        z: 100
      }
    ]
  }
}
if (option && typeof option === 'object') {
  myChart.setOption(option)
}
axios.get('./lib/data.json').then(({ data }) => {
  // console.log(data) // [["中国", "China", "2020", "1630525063168", "51780600", "31631"}, {}, {}, ......]
  // 定时器
  for (let i = 0; i < years.length; i++) {
    setTimeout(() => {
      let source = data.filter(item => item[2] == years[i])
      option.series[0].data = source
      option.graphic.elements[0].style.text = years[i]
      myChart.setOption(option)
    }, i * 1000)
  }
})
