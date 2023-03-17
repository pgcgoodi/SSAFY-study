<template>
  <div id="app">
    <h1>Hello Vue</h1>
    <LineChart />
    <DataForm />
  </div>
</template>

<script>
import {dataLab} from "./utils/axios.js";
import {mapState, mapMutations} from "vuex";
import LineChart from "./components/LineChart";
import DataForm from "./components/DataForm.vue";

export default {
  name: "App",
  components: { LineChart, DataForm },
  computed: {
    ...mapState(["chartData"]),
  },
  async created() {
    try {
      const response = await dataLab.get();
      const first = response.data[0];
      const labels = first.data.map((item) => item.period);
      const datasets = response.data.map((item) => {
        return {
          label: item.title,
          borderColor: this.makeColor(),
          data: item.data.map((item) => item.ratio),
          tension: 0.3
        }
      });
      const chartData = {
        labels: labels,
        datasets: datasets
      };
      this.CHANGE_CHART_DATA(chartData);
    } catch(error) {
      console.log(error);
    }
  },
  methods: {
    ...mapMutations(["CHANGE_CHART_DATA"]),
    makeColor() {
      return "#" + Math.round(Math.random() * 0xffffff).toString(16);
    }
  }
};
</script>

<style>
#app {
  font-family: Avenir, Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
}
</style>