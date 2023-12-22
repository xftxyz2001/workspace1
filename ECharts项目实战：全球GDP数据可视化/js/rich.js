const nations = [
  'America',
  'Argentina',
  'Australia',
  'Belgium',
  'Brazil',
  'Britain',
  'Canada',
  'China',
  'French',
  'Germany',
  'India',
  'Iran',
  'Italy',
  'Japan',
  'Korea',
  'Mexico',
  'Netherlands',
  'Russia',
  'Saudi',
  'Spain',
  'Sweden',
  'Swiss',
  'Turkey'
]
let rich = {}
nations.forEach(item => {
  rich[item] = {
    backgroundColor: {
      image: `./images/${item}.svg`
    },
    height: 32,
    width: 48
  }
})
